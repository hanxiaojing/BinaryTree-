size_t _kLevelSize(Node* root, int k)//默认根节点为第1层
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	//不可以传参数k--,不然只能是执行完这一句代码后k才会发生变化，k一直为3
	//不可以传参数--k,执行root->_left时，k变为2，执行root->_right时为同一层k变为1
	//传参数k-1
	return _kLevelSize(root->_left, k - 1) + _kLevelSize(root->_right, k - 1);
}

/*（1）递归写法：
依次访问根节点、左子树、右子树，注意递归出口的结束。*/


void _PrevOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->_data << "  ";
	_PrevOrder(root->_left);
	_PrevOrder(root->_right);
}

/*（2）非递归写法：
用栈模拟前序遍历，栈是先进先出的特点，则将无条件地入栈根节点，在弹出根节点之前依次将根节点的右孩子节点和左孩子节点入栈……*/


void _PrevOrder(Node* root)
{
	stack<Node*> s;
	if (root == NULL)
	{
		return;
	}

	s.push(root);
	while (!s.empty())
	{
		root = s.top();
		cout << root->_data << "  ";
		s.pop();
		if (root->_right)
		{
			s.push(root->_right);
		}
		if (root->_left)
		{
			s.push(root->_left);
		}
	}
}



/*二叉树中序：访问左子树->根节点->右子树
（1）递归写法：
依次访问左子树、根节点、右子树，注意递归出口的结束。*/


void _InOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	_InOrder(root->_left);
	cout << root->_data << "  ";
	_InOrder(root->_right);
}

/*（2）非递归写法：
wKiom1cZpWPDyNITAAAYiZTqWxI956.png
1、借助栈实现，先顺着二叉树找到最左边且最下边的节点3（一边找一边入栈），此时入栈序列为1，2，3。
2、此时按照中序遍历知道要弹出栈顶元素3，则弹出栈顶元素3。
3、下面该右子树了，那我们就要判断它的右子树是否为空，
若为空，往回返，该打印2了，那就弹出栈顶元素2。
若不为空，该右子树，指针指向右子树节点，再重复之前的步骤1，2，3……*/


void _InOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	stack<Node*> s;
	Node* cur = root;

	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}

		cur = s.top();    //将栈顶元素保存，以便于后面判断它是否有右孩子
		cout << s.top()->_data << "  ";
		s.pop();

		if (cur->_right == NULL)
		{
			cur = NULL;
		}
		else
		{
			cur = cur->_right;
		}
	}
}


/*二叉树后序：访问左子树->右子树->根节点
（1）递归写法：
依次访问左子树、右子树、根节点，注意递归出口的结束。*/


void _PostOrder(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	_PostOrder(root->_left);
	_PostOrder(root->_right);
	cout << root->_data << "  ";
}

/*（2）非递归写法：
1、后序遍历同样借助栈实现，先找到最左边且为最下面的节点3（一边入栈一边找）。
2、节点3若没有右孩子，那此时就打印节点3了，之后就弹出栈顶节点3
3、节点3若有右孩子，则要去继续遍历它的右子树，等遍历结束才可打印3.遍历重复步骤1，2，3……*/


void _PostOrderNon_R(Node* root)
{
	if (root == NULL)
	{
		return;
	}
	Node* cur = root;
	Node* prev = NULL;
	stack<Node*> s;

	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}

		cur = s.top();
		if (cur->_right == NULL || cur->_right == prev)
		{
			cout << cur->_data << "  ";
			s.pop();
			prev = cur;
			cur = NULL;
		}
		else
		{
			cur = cur->_right;
		}
	}
}
