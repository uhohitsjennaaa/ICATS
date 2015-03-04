Hey everyone.
Idk how good everyone is with GitHub, so I am adding instructions to clone and push to this repository.
I haven't added any information about the project, so later we can change this to a project description.

To clone this repository into your local GitHub folder, you have to use:
		git clone https://github.com/jwilso27/FundCompFinal.git

Then, before you can push or pull, you have to open .git/config with the editor
of your choice.  It should look like this:
[core]
        repositoryformatversion = 0
        filemode = true
        bare = false
        logallrefupdates = true
        ignorecase = true
        precomposeunicode = true
[remote "origin"]
        url = https://jwilso27@github.com/jwilso27/FundCompFinal.git
        fetch = +refs/heads/*:refs/remotes/origin/*
[branch "master"]
        remote = origin
        merge = refs/heads/master
        
Then, under remote url, change the user name to your own, but leave mine for
the repository path:
		url = https://USERNAME@github.com/jwilso27/FundCompFinal.git

After that, you should be able to push and pull.

If you want to add a file, after you open it in an editor and save it, use the
command:
		git add *
		
Then, to track the changes made to that version, use:
		git commit -m "summary of change"

Finally, to push the changed file, use:
		git push origin master
