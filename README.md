# cpp-drafts
Playground for cpp


#### Docker

##### Build docker image:

docker build . -t image_name


##### Run interactive container with local filesystem mapping:

docker run -it -v local/path:container/path image_name
