 while(temp!=NULL){
        if(temp->data==value){
            flag=1;//forward e treverse e temp=temp->next   backward e treverse  e temp=temp->prev
        }
        temp = temp->next;
    }