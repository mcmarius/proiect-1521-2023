tmux new-session -c "${GITHUB_WORKSPACE}" -s session -d "bash"
tmux send -t session "cd ${GITHUB_WORKSPACE} && script -f logs.txt" ENTER
tmux send -t session "./${ZIP_NAME}/${EXECUTABLE_NAME}" ENTER
tmux send-keys -t session "q"
tmux send-keys -t session "q" "z" "Enter"

tmux send -t session "exit" ENTER
tmux capture-pane -t session -S - -E - -p | cat -n
tmux send -t session "exit" ENTER

echo -e "\n\nProgram output\n\n"
ls -la
# cat logs.txt

