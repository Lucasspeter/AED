#  Lucas Simoes Peter M1

## 775. Global and Local Inversions

You are given an integer array nums of length n which represents a permutation of all the integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

0 <= i < j < n
nums[i] > nums[j]
The number of local inversions is the number of indices i where:

0 <= i < n - 1
nums[i] > nums[i + 1]
Return true if the number of global inversions is equal to the number of local inversions.

 

Example 1:

Input: nums = [1,0,2]
Output: true
Explanation: There is 1 global inversion and 1 local inversion.
Example 2:

Input: nums = [1,2,0]
Output: false
Explanation: There are 2 global inversions and 1 local inversion.
 

Constraints:

n == nums.length
1 <= n <= 105
0 <= nums[i] < n
All the integers of nums are unique.
nums is a permutation of all the numbers in the range [0, n - 1].


## Minha experiencia:

-Foi um trabalho bem complicado para falar a verdade, nao pela dificuldade do codigo em si porque vendo agora ele ate que e simples, porem tive muita dificuldade em aula para fazer ele, nao sei se foi pelo jeito diferente que ele foi apresentado, ou por ter feito quase nenhum exercicio de arvore avl, independente do motivo foi bem frustrante como nao consegui chegar em quase nada na aula, as ideias ate estavam ali mas nao sabia como implementar e depois aprendendo a solucao percebi como minhas ideias estavam realmente perto de estarem certas porem por nao saber como implementar o codigo dessas ideias acabei fazendo quase nada em aula o que foi bem frustrante visto que achava que iria melhor que isso.

## Leetcode:

<img width="764" height="427" alt="image" src="https://github.com/user-attachments/assets/29a0b771-4e1d-44b5-ab9e-0a85f7a903c7" />
