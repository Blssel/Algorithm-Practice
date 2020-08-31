# 排序专题(由难至易)
##快速排序
code
```C++

```

## 选择排序

## 插入排序


void quickSort(int A[], int left, int right){
    if(left==right) {
        return left;
    }
    int tmp = A[left];
    for(int i=right;i>left;i--){
        if(A[i]>=tmp){
            continue;
        }else{
            right = i;
            A[left] = A[right];
            break;
        }
    }
    for(int i=left;i<right;i++){
        if(A[i]<=tmp){
            continue;
        }else{
            left = i;
            A[left] = A[right];
            break;
        }
    }
}
void 
