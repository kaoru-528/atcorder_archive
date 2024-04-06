rep(i, 12){
        int w_count = 0;
        int b_count = 0;
        int w_count2  = w%7;
        int b_count2 =  b%5;
        if(S[i] == 'w'){
            w_count++;
        }
        else{
            b_count++;
        }
        if(w_count == w_count2 && b_count == b_count2){
            print("Yes");
            return 0;
        }
        else{
            print("No");
            return 0;
        }
    }