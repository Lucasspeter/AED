#  Lucas Simoes Peter M1

## 498.Diagonal Traverse

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:

Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:

Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
 

Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
-105 <= mat[i][j] <= 105


## Minha experiencia:

-Na aula acabei cometendo varios erros, por exemplo nao entendi exatamente como funcionava a matriz e tentei alocar memoria para ela(erro parecido ao que cometi no simulado, mas agora aprendi de vez essa parte eu espero), alem desse problema tambem tentei buscar varias logicas usando uma folha de papel para resolver o problema da martiz em diagonal porem nenhuma funcionou e por isso acabei nao colocando elas no codigo, a que chegou mais perto foi quando percebi que com varios if poderia resolver o problema( ate cheguei a comentar isso no codigo da aula ), mas nao consegui chegar na logica de subir com numero par e descer com numero impar que foi o que faltou para o codigo funcionar, parei em varios ifs que aumentavam e diminuiam os indices l e c. Chegando em casa procurei ajuda para perceber essa logica de quando estava subindo e quando estava descendo e depois de perceber ela ficou bem facil implementar minha ideia dos ifs, so tive um pouco de problema na ordem deles mas nada demais, e arrumei a alocacao desnescessaria de memoria que era um ponto que me causava bastante confusao mas acho que agora entendi.

## Leetcode:

<img width="732" height="441" alt="image" src="https://github.com/user-attachments/assets/483f9e57-5d6a-430a-85d4-cee2cbb05438" />
