[riot messaging service](https://technology.riotgames.com/news/riot-messaging-service)
- microservice architecture: provides separation of concerns, independent deployability, scalability, language flexibility
- traditional options for updating state: polling (every N seconds), update on relog (stale), persistent connections (requires one for each microservice)
- riot games approach: RMS