IMAGE_NAME = my-app
CONTAINER_NAME = my-app-container

.PHONY: build run stop clean up re

build:
	docker build -t $(IMAGE_NAME) $(PWD)

run:
	docker-compose up -d
	docker-compose run --rm app
stop:
	docker-compose down

clean:
	docker rmi $(IMAGE_NAME)
yalla:
	docker-compose run --rm app
	
up: build run

re: stop clean up
