# Uso:
#   ./count_moves.sh 3 2 1
#   ./count_moves.sh "4 3 2 1 0"

if [ $# -eq 0 ]; then
  echo "Uso: $0 <lista_de_numeros>"
  exit 1
fi

ARG="$@"
OPS=$(./push_swap $ARG | wc -l | tr -d ' ')
echo "ARG = $ARG"
echo "Número de operaciones: $OPS"
echo "Secuencia:"
./push_swap $ARG
