void insertData(Node** ptrRoot, int iNewData)
{
    Node *ptrLast = *ptrRoot; // para iterar na arvore
    // cria novo node
    Node *ptrProx = new Node; 
    ptrProx->iPayload = iNewData; 
    ptrProx->ptrRight = nullptr;
    ptrProx->ptrLeft = nullptr;
    
    // arvore vazia
    if (ptrLast == nullptr) 
    {
        *ptrRoot = ptrProx;
        return;
    }
    // coloca o elemento na posicao correta 
    while(true)
    {
        if(iNewData >= ptrLast->iPayload)
        {
            if(ptrLast->ptrRight == nullptr)
            {
                ptrLast->ptrRight = ptrProx;
                return;
            }
            ptrLast = ptrLast->ptrRight;
        }
        else
        {
            if(ptrLast->ptrLeft == nullptr)
            {
                ptrLast->ptrLeft = ptrProx;
                return;
            }
            ptrLast = ptrLast->ptrLeft;
        }
    }
    return;
}