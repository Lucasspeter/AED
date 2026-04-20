bool lemonadeChange(int* bills, int billsSize) {
    
    int troco = 0;
    bills = (int *)malloc(sizeof(int)* billsSize); //acho que o erro ta aqui mas nao lembro como fazer
    
    if(bills == NULL)
        printf("nao foi");
        else
        printf("foi");
    
    
    for(int i = 0; i < billsSize; i++){
        if(bills[i] == 5)
            troco = troco + 5;
    
        else if(bills[i] == 10)
            troco = troco;

        else if(bills[i] == 20)
            troco = troco - 15;
}
    
    for(int i = 0; i < billsSize; i++){ //so pra testar se tava dando errado o codigo e nao a logica, e ta
        printf("nota %d", bills[i]);
    }
    
    if(troco < 0){
        return false;
    }
    else{
        return true;
    }
}