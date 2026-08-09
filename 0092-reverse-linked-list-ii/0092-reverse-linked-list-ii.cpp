class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL) return NULL;
        if(left == right) return head;
        ListNode* before = NULL;
        ListNode* t = head;
        int pos = 1;
        while(pos<left){
            before = t;
            t = t->next;
            pos++;
        }

        ListNode* curr = t;
        ListNode* prev = NULL;
        int diff = right-left+1;
        while(diff--){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } 
        t->next = curr;
        if(before!=NULL){
            before->next = prev;
            return head;
        }
        return prev;
    }
};