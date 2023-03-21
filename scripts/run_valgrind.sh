tmux new-session -c "${GITHUB_WORKSPACE}" -s session -d "bash"
tmux send -t session ". ~/.bashrc" ENTER
tmux send -t session "cd ${GITHUB_WORKSPACE} && script -f logs.txt" ENTER
tmux send -t session "valgrind --leak-check=full --track-origins=yes --error-exitcode=1 --log-file=valgrind.txt ./${ZIP_NAME}/${EXECUTABLE_NAME}" ENTER
tmux send-keys -t session "q" "z" "Enter"
tmux send -t session "exit" ENTER
tmux capture-pane -t session -S - -E - -p | cat -n
tmux send -t session "exit" ENTER
ls -la

# echo -e "\n\nProgram output\n\n"
# cat logs.txt

# echo -e "\n\nValgrind output\n\n"
# cat valgrind.txt

