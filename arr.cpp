#include<iostream>
#include<vector>

#if 0
class Arr
{
public:

	Arr() = default;
	~Arr() = default;

	float push(float v)
	{
		mSum += v;
		std::swap(v, mData[mPushIdx]);
		mSum -= v;
		mPushIdx = (mPushIdx + 1) % mData.size();
	}

	void setSize(int n)
	{
		mData.resize(n, 0.0f);
	}

	//void reset()
	//{
	//	mPushIdx = 0;
	//	mSum = 0;
	//}

private:
	float              mSum = 0;
	std::vector<float> mData;
	int                mPushIdx = 0;
};
#endif

class Arr 
{
public:
	Arr() = default;

	float arrPush(float num)
	{
		if ( count == arr.capacity() ) 
		{
			count = 0;
		}
		if ( arr.size() < arr.capacity() ) 
		{
			arr.push_back(num);
			sum += num;
		}
		else {
			sum -= arr[count];
			arr[count] = num;
			sum += arr[count];
		}
		count++;
		return sum / arr.size();
	 }

	void funcSize( int n )
	{
		arr.reserve(n);
	}

	~Arr() = default;

private:
	float sum=0;
	int count = 0;
	std::vector<float> arr;
};



int main() {
	Arr arr1;
	arr1.funcSize(5);
	std::cout << arr1.arrPush(3) << std::endl;
	std::cout << arr1.arrPush(2) << std::endl;
	std::cout << arr1.arrPush(1) << std::endl;
	std::cout << arr1.arrPush(4) << std::endl;
	std::cout << arr1.arrPush(6.0) << std::endl;
	std::cout << arr1.arrPush(1.1) << std::endl;
	std::cout << arr1.arrPush(2.2) << std::endl;
	std::cout << arr1.arrPush(1.111) << std::endl;
	std::cout << arr1.arrPush(3.424) << std::endl;
	std::cout << arr1.arrPush(1.1241) << std::endl;
	std::cout << arr1.arrPush(242.2) << std::endl;
	system("pause");
	return 0;
}