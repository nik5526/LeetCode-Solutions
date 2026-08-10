void reverse(ListNode* left ,int size){
    ListNode* curr = left;
    ListNode* prev = NULL;
    while(size--){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return;
}

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* left = head;
        ListNode* right ;
        ListNode* res = NULL;
        ListNode* prevleft = NULL;
        int size = 2;

        while(true){
            right = left;
            for(int i =0;i<(size-1);i++){
                if(right == NULL){
                    break;
                }
                right = right->next;
            }
            if(right){
                ListNode* nextleft = right->next;
                reverse(left,size);
                if(prevleft){
                    prevleft -> next = right;
                }
                prevleft = left;
                if(res == NULL){
                    res = right;
                }
                left = nextleft;
            }
            else{
                if(prevleft){
                    prevleft->next = left;
                }
                break;
            }
        }
        return res;

    }
};