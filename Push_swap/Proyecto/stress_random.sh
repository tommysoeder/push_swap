# Uso:
#   ./stress_random.sh 5 20   # 20 tests con 1..5
#   ./stress_random.sh 100 10 # 10 tests con 1..100

if [ $# -lt 2 ]; then
  echo "Uso: $0 <N> <NUM_TESTS>"
  exit 1
fi

if [ -x ./checker ]; then
  CHECKER=./checker
elif [ -x ./checker_linux ]; then
  CHECKER=./checker_linux
else
  echo "No se encontró checker ni checker_linux en el directorio actual."
  exit 1
fi

N=$1
NUM_TESTS=$2
i=1
MAX_OPS=0

while [ $i -le $NUM_TESTS ]; do
  ARG=$(seq 1 $N | shuf)
  OPS=$(./push_swap $ARG | tee /tmp/ops_$$.log | wc -l | tr -d ' ')
  RES=$(cat /tmp/ops_$$.log | $CHECKER $ARG)
  rm -f /tmp/ops_$$.log
  echo "Test $i: ARG = $ARG -> $RES, ops = $OPS"
  if [ "$RES" != "OK" ]; then
    echo "❌ Problema encontrado en el test $i"
    exit 1
  fi
  if [ "$OPS" -gt "$MAX_OPS" ]; then
    MAX_OPS=$OPS
  fi
  i=$((i + 1))
done

echo "✅ Todos los $NUM_TESTS tests con 1..$N han dado OK."
echo "📊 Máximo número de operaciones observado: $MAX_OPS"
