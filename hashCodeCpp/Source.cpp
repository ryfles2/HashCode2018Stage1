#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Car {

	int carX = 0;
	int carY = 0;
	int time = 0;
	vector<long> rides;

};

struct Rides {
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

bool acompare(Rides lhs, Rides rhs) { return lhs.s < rhs.s; }

int main()
{
	long R = 0;
	long C = 0;
	long F = 0;
	long N = 0;
	long B = 0;
	long T = 0;

	Rides * rides_list;

	cin >> R;
	cin >> C;
	cin >> F;
	cin >> N;
	cin >> B;
	cin >> T;

	rides_list = new Rides[N];

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
		car[i].carX = 0;
		car[i].carY = 0;
		car[i].time = 0;
	}
	
	long time1 = 0;
	long time2 = LONG_MAX;;
	long nrCar = 0;

	sort(rides_list, rides_list + N, acompare);
	
	for (long i = 0; i < F; i++)
	{
		time1 = abs(rides_list[i].a - car[i].carX) + abs(rides_list[i].b - car[i].carY);
		time1 += rides_list[i].s + abs(rides_list[i].x - rides_list[i].a) + abs(rides_list[i].y - rides_list[i].b);
		car[i].carX = rides_list[i].x;
		car[i].carY = rides_list[i].y;
		car[i].time = time2;
		rides_list[i].flag = false;
		car[i].rides.push_back(rides_list[i].id);
	}

	for (long i = 0; i < N; i++)
	{
		if (rides_list[i].flag == true)
		{
			for (long j = 0; j < F; j++)
			{
				time1 = abs(rides_list[i].a - car[j].carX) + abs(rides_list[i].b - car[j].carY);
				time1 += rides_list[i].s + abs(rides_list[i].x - rides_list[i].a) + abs(rides_list[i].y - rides_list[i].b);
				if (time1 < time2)
				{
					time2 = time1;
					nrCar = j;
				}
			}
			car[nrCar].carX = rides_list[i].x;
			car[nrCar].carY = rides_list[i].y;
			car[nrCar].time = time2;
			rides_list[i].flag = false;
			time2 = LONG_MAX;
			//car[nrCar].addRide(i);
			car[nrCar].rides.push_back(rides_list[i].id);
			//car[nrCar].rides.push_back(i);         Wrong number ride to wector
			

		}

	}

	vector<long> rides;

	

	for (long j = 0; j < F; j++)
	{
		rides = car[j].rides;
		cout << rides.size() << " ";
		for (long i = 0; i < rides.size(); i++)
		{
			cout << rides[i] << " ";
		}
		cout << endl;
	}


	
	



	return 0;
}