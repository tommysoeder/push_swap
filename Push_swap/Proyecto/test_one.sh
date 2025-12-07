# Uso:
#   ./test_one.sh 3 2 1
#   ./test_one.sh "4 3 2 1"

if [ $# -eq 0 ]; then
  echo "Uso: $0 <lista_de_numeros>"
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

ARG="$@"
echo "ARG = $ARG"
echo "Operaciones:"
./push_swap $ARG
echo "Resultado del checker:"
./push_swap $ARG | $CHECKER $ARG
