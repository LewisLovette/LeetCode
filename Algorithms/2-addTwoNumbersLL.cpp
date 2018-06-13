/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int num1 = 0, num2 = 0;
        //Stepping through linkedlist, creating the two numbers
        while(l1->next != NULL or l2->next != NULL){
            num1 += l1->val;
            num2 += l2->val;
            
            l1 = l1->next;
            l2 = l2->next;
            
            num1 *= 10; //pushing 1 place so next val is added to the next *10
            num2 *= 10;
        }
        
        num1 += l1->val;
        num2 += l2->val;
        
        int sum = num1+num2;
        //cout << sum << endl;
        
        //Creating new list for the sum of the two numbers.
        ListNode * result = new ListNode(sum%10);
        ListNode * root = result;
        
        sum = (int)floor(sum/10);
        
        while(sum > 0){
            result->next = new ListNode(sum%10);
            sum = (int)floor(sum/10);
            result = result->next;
        }
        
        
        return root;
    }
};