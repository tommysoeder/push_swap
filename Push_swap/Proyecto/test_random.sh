# Uso:
#   ./test_random.sh 5 10   # 10 tests aleatorios con números del 1 al 5
#   ./test_random.sh 100 5  # 5 tests con 1..100

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

while [ $i -le $NUM_TESTS ]; do
  ARG=$(seq 1 $N | shuf)
  RES=$(./push_swap $ARG | $CHECKER $ARG)
  echo "Test $i: ARG = $ARG -> $RES"
  if [ "$RES" != "OK" ]; then
    echo "❌ Problema encontrado en el test $i"
    exit 1
  fi
  i=$((i + 1))
done

echo "✅ Todos los $NUM_TESTS tests aleatorios con 1..$N han dado OK."
