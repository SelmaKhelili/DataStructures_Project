#include"useraccount.h"
#ifndef BSTUSERS_H
#define BSTUSERS_H
#include<iostream>
using std::cout;

 class BinarySearchTree
 {
   public:
 	BinarySearchTree()
    : root{ nullptr }{}//constructor
 	 BinarySearchTree( const BinarySearchTree & rhs )//Copy constructor 
     : root{ nullptr }
 {
 	root = clone( rhs.root );
 }
 	BinarySearchTree( BinarySearchTree && rhs )//Move constructor
    {
        root = std::move( rhs.root );
        rhs.root=nullptr;
    }
 	~BinarySearchTree( )
 {
 	makeEmpty();
 }//distructor
 	const long long int & findMin() const
    {
        return  findMin(root)->user.getUserID();
    }
    UserAccount retreive(const long long int &id)
    {
       return retreive(id,root);
    }
    
    const long long int & findMax( ) const
    {
        return findMax(root)->user.getUserID();
    }
    bool contains( const long long int & x ) const
    {
        return contains(x,root);
    }
      bool contains( const UserAccount & account ) const
    {
        return contains(account.getUserID(),root);
    }
    bool isEmpty( ) const
    {
        return root==nullptr;
    }

	void makeEmpty()
    {
        makeEmpty(root);
    }
    void insert( const UserAccount & account )
    {
        insert(account,root);
    }
    void insert( UserAccount && account  )
    {
        insert( std::move( account ),root );
    }

    void remove( const UserAccount & account )
    {
        remove(account.getUserID(),root);
    }
     void remove( const long long int & id )
    {
        remove(id,root);
    }
	BinarySearchTree & operator=( const BinarySearchTree & rhs )
    {
        root = clone( rhs.root );
        return *this;
    }
	BinarySearchTree & operator=( BinarySearchTree && rhs )
    {
        root = std::move( rhs.root );
        rhs.root=nullptr;
    }
    void printTree( ostream & out = cout ) const
     {
 	if( isEmpty( ) )
 		out << "Empty tree" << endl;
 	else
 		printTree( root, out );
 }

  private:
 	struct BinaryNode
 	{
 		UserAccount user;
 		BinaryNode *left;
 		BinaryNode *right;

	BinaryNode( const UserAccount& account, BinaryNode *lt, BinaryNode *rt )
	   : user{ account }, left{ lt }, right{ rt } { }
 		BinaryNode( UserAccount& account, BinaryNode *lt, BinaryNode *rt )
 		   : user{ std::move( account ) }, left{ lt }, right{ rt } { }
 	};

	BinaryNode *root;

BinaryNode * clone( BinaryNode *t ) const
{
	if( t == nullptr )
    return nullptr;
	else
	    return new BinaryNode{ t->user, clone( t->left ), clone( t->right ) };
   }
 	void insert( const UserAccount& x, BinaryNode * & t )
     {
 	if( t == nullptr )
 	    t = new BinaryNode{ x, nullptr, nullptr };
	else if( x.getUserID() < t->user.getUserID() )
 	         insert( x, t->left );
 	     else if( x.getUserID() > t->user.getUserID())
 		      insert( x, t->right );
 		  else
 			; // Duplicate; do nothing
 }
    void insert( UserAccount&& x, BinaryNode * & t )
     {
 	if( t == nullptr )
 	    t = new BinaryNode{ std::move( x ), nullptr, nullptr };  
                 // std::move is exactly equivalent to a static_cast to an rvalue reference type
 	else if( x.getUserID() < t->user.getUserID() )
 		 insert( std::move( x ), t->left );
 	     else if( x.getUserID() > t->user.getUserID() )
	      insert( std::move( x ), t->right );
		  else
 			; // Duplicate; do nothing
 }
UserAccount retreive(long long int ID,BinaryNode *t)
{
    if(t== nullptr)
     return;
    else if(ID< t->user.getUserID())
     return retreive(ID,t->left);
    else if(ID> t->user.getUserID())
     return retreive(ID,t->right);
    else
      return t->user;
}
    void remove( const long long int & x, BinaryNode * & t )
     {
 	if( t == nullptr )
	    return; // Item not found; do nothing
	if( x < t->user.getUserID())
 	    remove( x, t->left );
 	else if( t->user.getUserID() < x )
 		 remove( x, t->right );
 	     else if( t->left != nullptr && t->right != nullptr ) // Two children
 		  {
 		      t->user=findMin( t->right )->user;
	 	      remove( t->user.getUserID(), t->right );
 		  }
		  else
 		  {
		      BinaryNode *oldNode = t;
 		      t = ( t->left != nullptr ) ? t->left : t->right;
 		      delete oldNode;
 		   }
 }
 	BinaryNode * findMin( BinaryNode *t ) const
     {
 	if( t == nullptr )
 		return nullptr;
	if( t->left == nullptr )
 		return t;
 	return findMin( t->left );
 }

	BinaryNode * findMax( BinaryNode *t ) const
     {
 	if( t != nullptr )
 	      while( t->right != nullptr )
 		  t = t->right;
 	return t;
 }
 	bool contains( const long long int & x, BinaryNode *t ) const
     {
 	if( t == nullptr )
  		 		return false;
 	else if( x < t->user.getUserID() )
         return contains( x, t->left );    
 else if( t->user.getUserID() < x )		
         return contains( x, t->right );	
   else	
    	return true; // Match
    }
 	void makeEmpty( BinaryNode * & t )
     {
 	if( t != nullptr )
 	{
 	    makeEmpty( t->left );
	    makeEmpty( t->right );
 	    delete t;
	}
 	t = nullptr;
}

void printTree( BinaryNode *t, ostream & out ) const
 {
 	if( t != nullptr )
 	{
 		printTree( t->left, out );
 		out <<t->user<< endl;
	printTree( t->right, out );
	}
 }
 };
#endif