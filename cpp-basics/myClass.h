class BitWise
{
	int value;
public:
	void set_value (int);
	int shift_left_by (int);
	int getValue () {return value;}

};

void BitWise::set_value (int x){
	value = x;
}

int BitWise::shift_left_by (int x){
	return value << x;
}


