rep(j, ans.size()){
        tmp[ans[j]] = "A";
        tmp[ans[j]+1] = "B";
        tmp[ans[j]+2] = "C";
        cnt[ans[j]] = 1;
        cnt[ans[j]+1] = 1;
        cnt[ans[j]+2] = 1;
    }