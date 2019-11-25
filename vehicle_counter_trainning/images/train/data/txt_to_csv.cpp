#include <bits/stdc++.h>

using namespace std;

const int value[4][2] = { 	{1 , 3},
							{2 , 4},
							{1 , 2},
							{2 , 3}
						};
const string name = "Loc";
const string edited_name = "vehicle";
// format id vehicle1_1_0001.jpg
int main(){
	ifstream fin;
	ofstream fout;
	fout.open("train_labels.csv");
	fout << "filename,width,height,class,xmin,ymin,xmax,ymax\n";
	for (int id = 0 ; id < 4 ; id ++ ){
		for (int part  = 0 ; part < 2 ; part ++){
			fin.open((name + char(id + 1 + '0') + "/train/" + name + char(id + 1 + '0') + "_" + char(value[id][part] + '0') + ".txt").c_str());
			int	frame_id, xmin, ymin, xmax, ymax;
			while(fin >> frame_id >> xmin >> ymin >> xmax >> ymax){
				fout << (edited_name + char(id + 1 + '0') + "_" + char(value[id][part] + '0') + "_") << setfill('0') << setw(4) << frame_id << ".jpg,";
				fout << "1920,";
				fout << "1080,";
				fout << "car,";
				fout << xmin  << ",";
				fout << ymin  << ",";
				fout << xmax  << ",";
				fout << ymax  << ",";	
				fout << "\n";
			}
			fin.close();
		}
	}
	fout.close();
	cout << "successful";
	return 0;
}