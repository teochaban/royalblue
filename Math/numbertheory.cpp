//Inverse of a mod m by extended euclidean
int inv(int a, int m)
{
    int temp=m, q, t, u=0, v=1;
    if(m==1) return 0;
    while(a>1)
    {
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=u;
         u=v-q*u;
         v=t;
    }
    if(v<0) v+=temp;
    return v;
}

//modular inverse of all numbers in [1,n] in O(n).
int inv[111111], n;
ll mod=1e9+7;
int main(void)
{
    cin>>n;
    int i;
    inv[1]=1;
    for(i=2 ; i<=n ; i++)
    {
        inv[i]=((mod-mod/i)*inv[mod%i])%mod;
        cout<<inv[i]<<endl;
    }
}


//Totient function sieve
void preprocess(void)
{
    int i, j;
    eulerphi[1]=1;
    for(i=2 ; i<=122000 ; i++)
    {
        eulerphi[i]=i;
        primechk[i]=1;
    }
    for(i=2 ; i<=122000 ; i++)
    {
        if(primechk[i]==1)
        {
            eulerphi[i]-=eulerphi[i]/i;
            for(j=2 ; i*j<=122000 ; j++)
            {
                primechk[i*j]=0;
                eulerphi[i*j]-=eulerphi[i*j]/i;
            }
        }
    }
}

//Mobius function sieve
void preprocess(void)
{
    int i, j;
    for(i=1 ; i<=111100 ; i++)
    {
        mu[i]=1;
        primechk[i]=1;
    }
    primechk[1]=0;
    for(i=2 ; i<=111100 ; i++)
    {
        if(primechk[i]==1)
        {
            mu[i]=-mu[i];
            for(j=2 ; i*j<=111100 ; j++)
            {
                primechk[i*j]=0;
                if(j%i==0)
                {
                    mu[i*j]=0;  
                }   
                else
                {
                    mu[i*j]=-mu[i*j];
                }
            }   
        }   
    }
}
