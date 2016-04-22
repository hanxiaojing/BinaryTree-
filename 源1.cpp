size_t _kLevelSize(Node* root, int k)//Ĭ�ϸ��ڵ�Ϊ��1��
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
	//�����Դ�����k--,��Ȼֻ����ִ������һ������k�Żᷢ���仯��kһֱΪ3
	//�����Դ�����--k,ִ��root->_leftʱ��k��Ϊ2��ִ��root->_rightʱΪͬһ��k��Ϊ1
	//������k-1
	return _kLevelSize(root->_left, k - 1) + _kLevelSize(root->_right, k - 1);
}

/*��1���ݹ�д����
���η��ʸ��ڵ㡢����������������ע��ݹ���ڵĽ�����*/


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

/*��2���ǵݹ�д����
��ջģ��ǰ�������ջ���Ƚ��ȳ����ص㣬������������ջ���ڵ㣬�ڵ������ڵ�֮ǰ���ν����ڵ���Һ��ӽڵ�����ӽڵ���ջ����*/


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



/*���������򣺷���������->���ڵ�->������
��1���ݹ�д����
���η��������������ڵ㡢��������ע��ݹ���ڵĽ�����*/


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

/*��2���ǵݹ�д����
wKiom1cZpWPDyNITAAAYiZTqWxI956.png
1������ջʵ�֣���˳�Ŷ������ҵ�����������±ߵĽڵ�3��һ����һ����ջ������ʱ��ջ����Ϊ1��2��3��
2����ʱ�����������֪��Ҫ����ջ��Ԫ��3���򵯳�ջ��Ԫ��3��
3��������������ˣ������Ǿ�Ҫ�ж������������Ƿ�Ϊ�գ�
��Ϊ�գ����ط����ô�ӡ2�ˣ��Ǿ͵���ջ��Ԫ��2��
����Ϊ�գ�����������ָ��ָ���������ڵ㣬���ظ�֮ǰ�Ĳ���1��2��3����*/


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

		cur = s.top();    //��ջ��Ԫ�ر��棬�Ա��ں����ж����Ƿ����Һ���
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


/*���������򣺷���������->������->���ڵ�
��1���ݹ�д����
���η����������������������ڵ㣬ע��ݹ���ڵĽ�����*/


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

/*��2���ǵݹ�д����
1���������ͬ������ջʵ�֣����ҵ��������Ϊ������Ľڵ�3��һ����ջһ���ң���
2���ڵ�3��û���Һ��ӣ��Ǵ�ʱ�ʹ�ӡ�ڵ�3�ˣ�֮��͵���ջ���ڵ�3
3���ڵ�3�����Һ��ӣ���Ҫȥ���������������������ȱ��������ſɴ�ӡ3.�����ظ�����1��2��3����*/


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
