#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Car
{
public:

	int corX, corY, time;
	vector<long> rides;

public:
	Car()
	{
		corX = 0;
		corY = 0;
		time = 0;
		rides.clear();
	}

	Car(int corX, int corY, int time)
	{
		this->corX = corX;
		this->corY = corY;
		this->time = 0;
	}

	Car(int corX, int corY, int time, vector<long> rides)
	{
		this->corX = corX;
		this->corY = corY;
		this->time = time;
		this->rides = rides;
	}
	~Car()
	{

	}

	void setCorX(int x)
	{
		corX = x;
	}

	void setCorY(int y)
	{
		corY = y;
	}

	void setTime(int t)
	{
		time = t;
	}

	int getCorX()
	{
		return corX;
	}

	int getCorY()
	{
		return corY;
	}

	int getTime()
	{
		return time;
	}

	int calcTime(int xFinish, int yFinish)
	{
		int result = abs(corX - xFinish) + abs(yFinish - corY);
		return result;
	}

	vector<long> getRides()
	{
		return rides;
	}

	void addRide(int number)
	{
		rides.push_back(number);
	}
};



struct rides {
	long a = 0;
	long b = 0;
	long x = 0;
	long y = 0;
	long s = 0;
	long f = 0;
	bool flag = true;
	long id = 0;
	long idCar = 0;


};

bool acompare(rides lhs, rides rhs) { return lhs.s < rhs.s; }

int main()
{
	long R = 0;
	long C = 0;
	long F = 0;
	long N = 0;
	long B = 0;
	long T = 0;

	rides * rides_list;

	cin >> R;
	cin >> C;
	cin >> F;
	cin >> N;
	cin >> B;
	cin >> T;

	rides_list = new rides[N];

	for (long i = 0; i < N; i++)
	{
		cin >> rides_list[i].a;
		cin >> rides_list[i].b;
		cin >> rides_list[i].x;
		cin >> rides_list[i].y;
		cin >> rides_list[i].s;
		cin >> rides_list[i].f;
		rides_list[i].id = i;
	}

	Car * car = new Car[F];


	for (long i = 0; i < F; i++)
	{
		car[i].setCorX(0);
		car[i].setCorY(0);
		car[i].setTime(0);
	}
	
	long time1 = 0;
	long time2 = LONG_MAX;;
	long nrCar = 0;

	sort(rides_list, rides_list + N, acompare);
	
	for (long i = 0; i < F; i++)
	{
		time1 = abs(rides_list[i].a - car[i].getCorX()) + abs(rides_list[i].b - car[i].getCorY());
		time1 += rides_list[i].s + abs(rides_list[i].x - rides_list[i].a) + abs(rides_list[i].y - rides_list[i].b);
		car[i].setCorX(rides_list[i].x);
		car[i].setCorY(rides_list[i].y);
		car[i].setTime(time2);
		rides_list[i].flag = false;
		car[i].rides.push_back(i);
	}

	for (long i = 0; i < N; i++)
	{
		if (rides_list[i].flag == true)
		{
			for (long j = 0; j < F; j++)
			{
				time1 = abs(rides_list[i].a - car[j].getCorX()) + abs(rides_list[i].b - car[j].getCorY());
				time1 += rides_list[i].s + abs(rides_list[i].x - rides_list[i].a) + abs(rides_list[i].y - rides_list[i].b);
				if (time1 < time2)
				{
					time2 = time1;
					nrCar = j;
				}
			}
			car[nrCar].setCorX(rides_list[i].x);
			car[nrCar].setCorY(rides_list[i].y);
			car[nrCar].setTime(time2);
			rides_list[i].flag = false;
			time2 = LONG_MAX;
			//car[nrCar].addRide(i);
			car[nrCar].rides.push_back(i);
			

		}

	}

	vector<long> rides;

	

	for (long j = 0; j < F; j++)
	{
		rides = car[j].getRides();
		cout << rides.size() << " ";
		for (long i = 0; i < rides.size(); i++)
		{
			cout << rides[i] << " ";
		}
		cout << endl;
	}


	
	



	return 0;
}