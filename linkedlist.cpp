#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};
Node* takingInput(){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;
    Node*head= NULL;
    Node*tail=NULL;
    while(data!=-1){
        Node*n = new Node(data);
        if (head==NULL){
            head=n;
            tail=n;
        }
        else{
            tail->next=n;
            tail=n;
        }
        cin>>data;
    }
    return head;
}
void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"NULL"<<endl;
}
int length(Node*head){
    int count=0;
    while(head!=NULL){
        count+=1;
        head=head->next;
    }
    return count;
}
Node*printIitposition(Node*head){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    int a=count/2;
    for (int i=1;i<a;i++){
        head=head->next;
    }
    return head;
}
Node*insertAtIithpos(Node*head,int value,int pos){
    if (pos<0){
        return head;
    }
    if (pos==0){
        Node*n=new Node(value);
        n->next=head;
        head=n;
        return head;
    }
    Node*copyhead=head;
      for (int i=1;i<pos;i++){
          copyhead=copyhead->next;
      }
      cout<<copyhead->data;
    if(head){
        
      Node*n=new Node(value);
      Node*temp=head->next;
      head->next=n;
      n->next=temp;
      return copyhead;

    }
    return copyhead;
}
Node* reverse(Node*head){
    if (head==NULL){
        return head;
    }
    head->next=head;
    reverse(head->next);
    cout<<(head->data)<<" ";
    return head;
}
Node* middle(Node*head){
    int count=0;
    Node*temp=head;
    
    while(temp!=NULL){
        count+=1;
        temp=temp->next;
    }
    cout<<temp->data;
    int n=count/2;
    //cout<<n;
    for (int i=0;i<n;i++){
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<temp->data;
    return temp;
}
Node* deleteoperation(Node*head,int element){
    if(head->data==element){
        Node*copyhead=head->next;
        delete head;
        return copyhead;
    }
   
    Node*prev=head;
    Node*curr;
    
   curr=prev->next;
    while(curr!=NULL){
      
        if (curr->data==element){
            Node*temp=curr;
            prev->next=curr->next;
            delete temp;
            
        }
        curr=curr->next;
        prev=prev->next;
        return head;
    }
    return NULL;
}
 Node* mergeTwoLists(Node* list1,Node* list2) {
     if (!list1) return list2;
     if (!list2) return list1;
        Node*list3=list1;
        if (list1->data>list2->data){
            list3=list2;
            list2=list2->next;
        }
        else{
            list1=list1->next;
        }
        Node*curr=list3;
        while(list1 && list2){
            if (list1->data<list2->data){
                
                curr->next=list1;
                list1=list1->next;
                
            }
            else{
                curr->next=list2;
                list2=list2->next;
            }
            curr=curr->next;
        }
        if (!list1){
            curr->next=list2;
        }
        else{
            curr->next=list1;
        }
    return list3;
}
Node *getIntersectionNode(Node *headA, Node *headB) {
    int count1=0;
    int count2=0;
    Node*temp1=headA;
    Node*temp2=headB;
        while(temp1||temp2){
            if(temp1){
                count1+=1;
                temp1=temp1->next;
            }
            else{
                count2+=1;
                temp2=temp2->next;
            }
        }
        cout<<count1<<" "<<count2<<endl;
        int diff=abs(count1-count2);
        cout<<diff<<endl;
        for (int i=0;i<diff;i++){
            if (count1>count2){
                headA=headA->next;
            }
            else{
                headB=headB->next;
            }
            
        }
        while(headA&&headB){
            if (headA->data==headB->data){
                return headA;
            }
            else{
                headA=headA->next;
                headB=headB->next;
            }
        }
        return NULL;
    }
    Node* noduplicate(Node*head){
        if (!head) return NULL;
        Node*prev=head;
        Node*curr=prev->next;
        //cout<<prev->data;
        while(curr!=NULL){
            if (curr->data!=prev->data){
                prev->next=curr;
                curr=curr->next;
                prev=prev->next;
            }
           else{
               Node*temp=curr;
               prev->next=temp->next;
               curr=curr->next;
               delete temp;
           }
            
        }
        return head;
    }
int numComponents(Node* head, vector<int>& nums) {
        if (!head) return 0;
        if (nums.size()==0) return 0;
        Node*curr=head;
        int count=0;
        int i=0;
        while(i<nums.size()-1 && curr!=NULL){
            if (nums[i]==curr->data){
                curr=curr->next;
                if (nums[i+1]==curr->data){
                    count+=1;
                    i++;
                }
            }
            curr=curr->next;
        }
        return count;
    }
    Node* odd_even(Node*head){
        Node*temp=head;
        //cout<<temp->data;
        vector<Node*> vec;
        while(temp!=NULL){
            if ((temp->data)%2!=0){
                vec.push_back(temp);
                temp=temp->next;
            }
            else{
            temp=temp->next;
            }
        }
        Node*temp1=head;
        while(temp1!=NULL){
            if((temp1->data)%2==0){
                
                vec.push_back(temp1);
                temp1=temp1->next;
                }
                else{
                    temp1=temp1->next;
                }
        }
        Node*odd=vec[0];
        Node*even=odd;
        for(int i=1;i<vec.size();i++){
           
            odd->next=vec[i];
            odd=odd->next;
            if (i==vec.size()-1){
                 
                odd->next=NULL;
           }
        }
        return even;
    }
    Node*swapv(Node*head,int k){
        int count=0;
        Node*curr=head;
        while(curr){
            count+=1;
            curr=curr->next;
        }
        int start=k;
        Node*startList=head;
        int i=1;
        while(i<start){
            startList=startList->next;
            i++;
        }
        int end=count-k;
        Node*endList=head;
        int j=0;
        while(j<end){
            endList=endList->next;
            j++;
        }
        int temp=startList->data;
        startList->data=endList->data;
        endList->data=temp;
        return head;
    }
    void Next(Node*head){
        vector<int> vec;
        while(head){
            vec.push_back(head->data);
            head=head->next;
        }
        vector<int> result;
        int val=(distance(vec.begin(),max_element(vec.begin(),vec.end())));
        cout<<val;
        

    }
    void splitval(Node*head,int k){
        vector<vector<int>>results;
        
        int count=0;
        Node*temp=head;
        while(head){
            count+=1;
            temp=temp->next;
        }
        int mod=count%k;
        Node*curr=head;
        int target=mod;
        if (count<k){
            for(int i=0;i<k;i++){
                results[i][0]=curr->data;
                curr=curr->next;
            }
        }
        else{
            if (curr){
            for(int i=0;i<mod;i++){
                results[0][i]=curr->data;
                curr=curr->next;
            }
            for(int i=mod;i<k;i++){
                for(int j=target;j<target+k;j++){
                    results[i][j]=curr->data;
                    curr=curr->next;
                    if(j==(target+k)-1){
                        target=j;
                    }
                }
            }

        }
    }
        cout<<results[0][1];
    }
    void reverse_2(Node*head){
        map<int,Node*> mp;
        Node*temp=head;
        int i=0;
        while(temp){
            
        }
        for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
        cout << itr->first
             << '\t' << itr->second->data<< '\n';
    }

    }
    Node*deleteFromEnd(Node*head,int n){
        if(!head) return NULL;
        int count=0;
        Node*temp=head;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        Node*curr=head;
        int dist=count-n;
        if(dist==0) return head->next;
        if(count==1 && n==1 ){
            return NULL;
        }
        while(dist>1){
            curr=curr->next;
            dist--;
        }
        Node*prev=curr;
        Node*del=prev->next;

        
        
        curr->next=prev->next->next;
        delete del;
        
        return head;
    }
    Node*mergeList(Node*head1,Node*head2){
        Node*temp1=head1;
        Node*temp2=head2;
        while(temp2!=NULL){
            while(temp1!=NULL){
                if(temp2->data<head1->data){
                    Node*value=new Node(temp2->data);
                    value->next=head1;
                    head1=value;
                    temp1=temp1->next;
                }
                if(temp1->data<temp2->data && temp1->next->data>temp2->data){
                    Node*copyhead=temp1->next;
                    Node*value=new Node(temp2->data);

                    temp1->next=value;
                    temp1->next->next=copyhead;
                    temp1=temp1->next;
                }
                if(temp1->next==NULL && temp1->data<temp2->data){
                    Node*value=new Node(temp2->data);
                    temp1->next=value;
                    temp1=temp1->next;
                }
            }
            temp2=temp2->next;
        }
    }
    Node* reverseBetween(Node* head, int left, int right) {
        if(left==right){
            return head;
        }
        if(!head) return head;
        stack<Node*> st;
        Node*templeft=head;
        Node*tempright=head;
        while(left>0){
            templeft=templeft->next;
            left--;
        }
        Node*start=templeft->next;
        //cout<<templeft->data;
        while(right>0){
            tempright=tempright->next;
            right--;
        }
        
        while(start->data!=tempright->data){
            st.push(start);
           // cout<<start->data;
            start=start->next;
        }
        while(!st.empty()){
            templeft->next=st.top();
           // cout<<st.top()->data;
            
            templeft=templeft->next;
            st.pop();
        }
        templeft->next=tempright;
        return head;
    }
     Node* removeNodes(Node* head) {
        vector<int> temp_v;
        Node*temp=head;
        while(temp!=NULL){
            
            temp_v.push_back(temp->data);
            temp=temp->next;
        }
        
        vector<int> final_del={0,0,1,0,1};
        
        Node*new_val=NULL;
        Node*temp1=head;
        int i=0;
        int count=0;
        while(temp1!=NULL){
            
            if(final_del[i]==1){
                
                Node*n =new Node(temp1->data);
                
                if(new_val==NULL){
                    new_val=n;
                }
                else{
                    
                    new_val=n;
                    new_val->next=new_val;
                }
                
                i++;
                temp1=temp1->next;
             
            }
            else{
                
            i++;
            temp1=temp1->next;
            }
        }
        
        
        
        return new_val;
    }
int main(){
//    Node*head=takingInput();
//    print(head);
   //Node*head2=takingInput();
   //print(head2);
  // int len=length(head);
   //cout<<len<<endl;
  // int pos=5;
  // Node*head4=printIitposition(head);
   //print(head4);
   //Node*head5=deleteoperation(head,4);
   //print(head5);
  // Node*head2=insertAtIithpos(head,20,pos);
   //print(head2);
//   Node*head2=reverse(head);
//    cout<<head2->data<<endl;
  // print(head2);
 // Node*head3=middle(head);
  //print(head3);
  //Node*list=mergeTwoLists(head,head2);
  //print(list);
  //Node*list1=getIntersectionNode(head,head2);
  //print(list1);
  //Node*list3=noduplicate(head);
 // print(list3);
 //vector<int> nums={0,3,1,4};
 //int len= numComponents(head,nums);
 //cout<<len;
 //Node*odd=odd_even(head);
 //print(odd);
 //Node*swapval=swapv(head,5);
 //print(swapval);
 //Next(head);
 //splitval(head,5);
//   reverse_2(head);
 
//  int n=2;
//  Node*del=deleteFromEnd(head,n);
//  print(del);
  //deleteFromEnd(head,n);
  Node*head1=takingInput();
  print(head1);
//   Node*head2=takingInput();
//   print(head1);
//   print(head2);
//   Node*mergelist=mergeList(head1,head2);
//   print(mergelist);
   Node*rev=removeNodes(head1);
   print(rev);
    return 0;
}