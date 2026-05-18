#  Lucas Simoes Peter M1

## 503. Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]

Output: [2,-1,2]

Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.
Example 2:

Input: nums = [1,2,3,4,3]

Output: [2,3,4,-1,4]
 

Constraints:

1 <= nums.length <= 104
-109 <= nums[i] <= 109


## Minha experiencia:

-Dessa vez consegui fazer tudo em aula e fiquei bem feliz com isso. Comecei pensando em que tipo de estrutura deveria usar, confesso que no inicio demorei um pouco para entender que teria que ser pilha, mas depois que entendi, o exercicio ficou bem mais facil. Apos isso, so precisei implementar a logica, nessa parte o ponto mais dificil foi saber como fazer o vetor ser circular, mas apos algumas ideias erradas lembrei que tinha como fazer vetor circular usando i % numsSize, e a partir dai o codigo funcionou.


## Leetcode:

<img width="753" height="436" alt="image" src="https://github.com/user-attachments/assets/1836f3a1-a94f-4be7-a8c1-a11e055c140c" />
