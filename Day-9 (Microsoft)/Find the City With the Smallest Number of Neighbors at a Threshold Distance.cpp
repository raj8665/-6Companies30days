// LeetCode - 1334

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // We are using the floyd-Warshal algorithm to for the shortest distance 
        // we can also solve this using the Dijkstra's Algo
        vector<vector<int>> dis(n,vector<int> (n,INT_MAX));
        for (auto it : edges){
            dis[it[0]][it[1]] = it[2];
            dis[it[1]][it[0]] = it[2];
        }
        for(int i=0;i<n;i++) dis[i][i] = 0;

        // Now computing path via iterating all the possible cases 
        for(int via = 0; via<n;via++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dis[j][via]==INT_MAX || dis[via][k]==INT_MAX){
                        continue;
                    }
                    dis[j][k] = min(dis[j][k],dis[j][via]+dis[via][k]);
                }
            }
        }

        int mCity=n, cityNo = -1;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(dis[i][j]<=distanceThreshold) cnt++;
            }

            if(cnt<=mCity){
                mCity = cnt;
                cityNo = i;
            }
        }

       return cityNo;
    }