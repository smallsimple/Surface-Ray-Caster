lambd=[1,1,0.5,1,-1];
sigma=[1,0.25,1,1,1];
mux=[0,0,0,1,0];
x=linspace(-5,5,100);
y=lambd(1)*exp(-sigma(1)*(x-mux(1)).*(x-mux(1)));
y(2,:)=lambd(2)*exp(-sigma(2)*(x-mux(2)).*(x-mux(2)));
y(3,:)=lambd(3)*exp(-sigma(3)*(x-mux(3)).*(x-mux(3)));
y(4,:)=lambd(4)*exp(-sigma(4)*(x-mux(4)).*(x-mux(4)));

area(x,y(1,:))
area(x,y(2,:))
area(x,y(3,:))
area(x,y(4,:))