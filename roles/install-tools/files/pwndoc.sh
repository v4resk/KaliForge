#!/bin/bash

if [[ $1 == "-h" ]]; then
    echo "Usage: ./script.sh [command]"
    echo "Commands:"
    echo "  init    - Run 'docker-compose up -d --build'"
    echo "  start   - Run 'docker-compose start'"
    echo "  stop    - Run 'docker-compose stop'"
    echo "  remove  - Run 'docker-compose down'"
    echo "  update  - Run 'docker-compose down', 'git pull', and 'docker-compose up -d --build'"
    exit 0
fi

case "$1" in
    init)
        docker-compose up -d --build
        ;;
    start)
        docker-compose start
        ;;
    stop)
        docker-compose stop
        ;;
    remove)
        docker-compose down
        ;;
    update)
        docker-compose down
        git pull
        docker-compose up -d --build
        ;;
    *)
        echo "Invalid command. Use './script.sh -h' for help."
        exit 1
        ;;
esac