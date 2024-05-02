#include<iostream>
#include<cstdlib>
using namespace std;

class employee {
public:
    int empid;
    string ename, designation;
    float esal;
    employee* left;
    employee* right;

    employee(int eid, string empname, string desig, float sal) {
        empid = eid;
        ename = empname;
        designation = desig;
        esal = sal;
        left = NULL;
        right = NULL;
    }
};

void addEmp(employee* &root, int eid, string empname, string desig, float sal) {
    if (root == NULL) {
        root = new employee(eid, empname, desig, sal);
    } else {
        if (sal < root->esal) {
            addEmp(root->left, eid, empname, desig, sal);
        } else {
            addEmp(root->right, eid, empname, desig, sal);
        }
    }
}

void createEmp(employee* &root) {
    int num_emp, eid;
    string empname, desig;
    float sal;
    
   // root = new employee(eid, empname, desig, sal);
    cout << "\nEnter number of Employee to add: ";
    cin >> num_emp;
    for (int i = 1; i <= num_emp; i++) {
        cout << "\nEnter Employee ID: ";
    cin >> eid;
    cout << "\nEnter Employee name: ";
    cin >> empname;
    cout << "\nEnter Employee designation: ";
    cin >> desig;
    cout << "\nEnter Employee salary: ";
    cin >> sal;
        //cin >> eid >> empname >> desig >> sal;
        addEmp(root, eid, empname, desig, sal);
    }
}
void Delete(employee* root)
{

}
employee* min(employee* root)
{
    if(root==NULL)
    {
        cout<<"\nempty";
    }
    while(root->left!=NULL)
    {
        root=root->left;
    }
    cout<<"\nEmployee with minimum salary:"<< root->esal;
}
employee* search(employee* root)
{
    string key;
    cout<<"\nEnter employee name which is to be search: ";
    cin>>key;
    if(root==NULL)
    {
        cout<<"\nEmpty";
    }
    if(root->ename==key)
    {
        cout<<"\nKey found: "<<root->ename;
    }
    employee* found=search(root->right);
    if(found==NULL)
    {
        found=search(root->left);
    }
    return found;
}
void inorderTraversal_Emp(employee* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal_Emp(root->left);
    cout << "\nEmployee ID: " << root->empid << "\tEmployee Name: " << root->ename << "\tEmployee Designation: " << root->designation << "\tEmployee Salary: " << root->esal;
    inorderTraversal_Emp(root->right);
}

int main() {
    employee* root = NULL;
    createEmp(root);
    inorderTraversal_Emp(root);
    search(root);
    return 0;
}
