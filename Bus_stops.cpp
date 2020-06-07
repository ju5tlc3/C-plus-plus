//Performed buses and stops list.
//There are four commands: ALL_BUSES, BUSES_FOR_STOP, NEW_BUS, STOPS_FOR_BUS
//Functionality of ALL_BUSES and NEW_BUS is understood.
//BUSES_FOR_STOP prints a list of buses which has the given stop in the route
//STOPS_FOR_BUS prints a list of stops interchanges of the bus route

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>


using std::cout;
using std::cin;
using std::string;
using std::map;
using std::endl;
using std::vector;

int main()
{
	int num,stops_count;
	cin >> num;
	string com,stop,bus;
	vector<string> buses;
	map<string, vector<string>> buses_map;
	for (int i = 0; i < num; i++)
	{
		cin >> com;
		if (com != "ALL_BUSES")
		{
			if (com != "BUSES_FOR_STOP")
			{
				cin >> bus;
				if (com == "NEW_BUS")
				{
					/*New bus*/
					cin >> stops_count;
					buses.push_back(bus);
					for (int i = 0; i < stops_count; i++)
					{
						cin >> stop;
						buses_map[bus].push_back(stop);
					}
					continue;
				}
				/*Stop for bus*/
				if (buses_map[bus].empty())
				{
					cout << "No bus" << endl;
					continue;
				}
				int bus_count = 0;
				for (auto stop : buses_map[bus])
				{
					cout << "Stop " << stop << ": ";
					{
						for (auto b : buses)
						{
							if (b != bus)
							{
								bus_count += std::count(buses_map[b].begin(), buses_map[b].end(), stop);
								if (std::count(buses_map[b].begin(), buses_map[b].end(), stop) > 0)
								{
									cout << b << " ";
								}
							}
						}
						if (bus_count == 0)
						{
							cout << "no interchange";
						}
					}
					cout << endl;
					bus_count = 0;
				}
				continue;
			}
			int stop_count = 0;
			/*Buses for stop*/
			cin >> stop;
			for (auto b : buses)
			{
				stop_count += std::count(buses_map[b].begin(), buses_map[b].end(), stop);
				if (std::count(buses_map[b].begin(), buses_map[b].end(), stop) > 0)
				{
					cout << b << " ";
				}
			}
			if (stop_count == 0)
			{
				cout << "No stop";
			}
			cout << endl;
			continue;
		}

		/*All buses*/
		if (buses_map.empty())
		{
			cout << "No buses" << endl;
			continue;
		}
		for (auto bus : buses_map)
		{
			cout << "Bus " << bus.first << ":";
			for (auto stop : bus.second)
			{
				cout << " " << stop;
			}
			cout << endl;
		}
	}
	return 0;
}
