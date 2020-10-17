# HacktoberFest-2020
Repository designed for beginner to contribute to open-source 


## ❓ What is Hacktoberfest 2020?

Hacktoberfest 2020 is a month long virtual festival event to celebrate open source contributions presented by Digital Ocean, Intel and DEV. It is the easiest way to get into open source!
https://hacktoberfest.digitalocean.com/
During the entire month of October 2020, all you have to do is contribute to any open source projects and open at least 4 pull requests. Yes, any project and any kind of contributions. You don’t need to be an expert in programming or coding. It can be a be a bug fix, improvement, or even a documentation change! And win an awesome T-shirt and awesome stickers.

## 😕 Why Should I Contribute?

The Hacktoberfest’s simple plain objective is:

    Support open source and earn a limited edition T-shirt!

But, it’s not just about the t-shirts or stickers. Its about supporting open source. Its about celebrating open source, and giving it back. If you’ve never contributed to open source before, this is the perfect time to get started because Hacktoberfest provides a large list of available contribution opportunities (and yes, there are always plenty for beginners too).

## 👌 What Can I Contribute?

Hacktoberfest® is open to everyone in our global community. Whether you’re a developer, student learning to code, event host, or company of any size, you can help drive growth of open source and make positive contributions to an ever-growing community. All backgrounds and skill levels are encouraged to complete the challenge.

It doesn’t need to be code. It can be even documentation. Or spelling fix.

You can contribute to any open source project hosted on Github.com and contribute anything between October 1 to October 31 midnight in 2020. You will find plenty of issues labeled with hacktoberfest or good-first-issue etc on Github. These will be the simple ones most probably and easy to fix.

## How to contribute
Submit your pull request here for Hacktoberfest-2020 in any language you prefer, if language folder not present, create one as a part of it, after script add your name and GitHub profile into Contributors.md file.

👕 Win Your T-Shirt

In past years, shirts have arrived in November or December, depending on how far you live from San Francisco.

The Digital Ocean team should eventually contact you asking for your shirt size and shipping address. (Keep in mind they are shipping 40,000 shirts so this process will take a while.) And yes, they will ship internationally.

Don’t miss this opportunity. Start contributing to open source and get a limited edition T-shirt for Free! And also, Stickers!


![image here](https://github.com/sujata13/HacktoberFest-2020/blob/master/hacktober.png)

# Event details
Hacktoberfest® is open to everyone in our global community. Whether you’re a developer, student learning to code, event host, or company of any size, you can help drive growth of open source and make positive contributions to an ever-growing community. All backgrounds and skill levels are encouraged to complete the challenge.

Hacktoberfest is open to everyone in our global community!
Pull requests can be made in any GitHub-hosted repositories/projects.
Sign up anytime between October 1 and October 31.

# Rules
To qualify for the official limited edition Hacktoberfest shirt, you must register and make four pull requests (PRs) between October 1-31 (in any time zone). PRs can be made to any public repo on GitHub, not only the ones with issues labeled Hacktoberfest. If a maintainer reports your pull request as spam or behavior not in line with the project’s code of conduct, you will be ineligible to participate. This year, the first 70,000 participants who successfully complete the challenge will earn a T-shirt.


# Do's and Dont's of Hacktoberfest
<h4>Don't: open pull requests with minor text edits on other people's repositories</h4>
 If you're looking for a faster way to open four PR's and win, there's a better way!

<h4>Do: Follow a repository's contribution guidelines</h4>
 Almost every repo looking for help has a CONTRIBUTING.md file in it, read it first!

<h4>Don't: feel intimidated</h4>
 Register for an event and learn with a group, or connect with others in the Discord chat or Telegram Group(https://t.me/hacktober_fest_2020).

## Getting Started

* Add your name to the CONTRIBUTORS.md file using following model

```markdown
Name: [YOUR NAME](Github Link)
Place: city you belong to
About: Short Intro (Optional)
```
## Support

Check [Contribution](/CONTRIBUTION.md) Guide Before Contribution.

## Instructions:

*Make sure you have a GitHub account. In case you don't have one, you can create your account by visiting https://github.com/ and clicking on ``Sign up`` option at the top right corner.*

### 1. Register yourself for Hacktoberfest
###### Link to register: https://hacktoberfest.digitalocean.com/
Click on "Start Hacking" and add your GitHub account.

![Screenshot-HFST](https://github.com/bajajvinamr/HacktoberFest2020/blob/master/1.png)



### 2. Star and Fork this Repository
###### You can star and fork this repository on GitHub by navigating at the top of this repository.

GitHub repository URLs will reference both the username associated with the owner of the repository, as well as the repository name. For example, acmbvp is the owner of the Hacktoberfest repository, so the GitHub URL for this project is:

https://github.com/sujata13/HacktoberFest-2020


When you’re on the main page of a repository, you’ll see a button to "Star" and “Fork” the repository on the upper right-hand side of the page, underneath your user icon.

### 3. Clone the Repository

To make your own local copy of the repository you would like to contribute to, let’s first open up a terminal window.

We’ll use the `git clone`  command along with the URL that points to your fork of the repository.

This URL will be similar to the URL above, except now it will end with `.git.` In the cloud_haiku example above, the URL will look like this:
https://github.com/your-username/Hacktoberfest.git

You can alternatively copy the URL by using the green “Clone or download” button from your repository page that you just forked from the original repository page. Once you click the button, you’ll be able to copy the URL by clicking the binder button next to the URL:


Once we have the URL, we’re ready to clone the repository. To do this, we’ll combine the git clone command with the repository URL from the command line in a terminal window:

`git clone https://github.com/your-username/Hacktoberfest.git`


### 4. Create a New Branch

To create your branch, from your terminal window, change your directory so that you are working in the directory of the repository. Be sure to use the actual name of the repository (i.e. Hacktoberfest) to switch into that directory.

#####    `cd Hacktoberfest`

Now, we’ll create our new branch with the git branch command. Make sure you name it descriptively so that others working on the project understand what you are working on.


##### `git branch new-branch`

Now that our new branch is created, we can switch to make sure that we are working on that branch by using the git checkout command:

##### ` git checkout new-branch `

Once you enter the git `checkout` command, you will receive the following output:

######  `Output:`
#####  `Switched to branch 'new-branch' `


At this point, you can now modify existing files or add new files to the project on your own branch.

#### Make Changes Locally

Once you have modified existing files or added new files to the project, you can add them to your local repository, which you can do with the git add command. Let’s add the -A flag to add all changes that we have made:

##### ` git add -A ` or ` git add . `

Next, we’ll want to record the changes that we made to the repository with the git commit command.

*The commit message is an important aspect of your code contribution; it helps the other contributors fully understand the change you have made, why you made it, and how significant it is. Additionally, commit messages provide a historical record of the changes for the project at large, helping future contributors along the way.*


If you have a very short message, you can record that with the -m flag and the message in quotes:

###### ` Example: `
##### ` git commit -m "Updated Readme.md" `

###### At this point you can use the git push command to push the changes to the current branch of your forked repository:
###### ` Example:`
##### ` git push --set-upstream origin new-branch `

### 5. Update Local Repository

*While working on a project alongside other contributors, it is important for you to keep your local repository up-to-date with the project as you don’t want to make a pull request for code that will cause conflicts. To keep your local copy of the code base updated, you’ll need to sync changes.*

We’ll first go over configuring a remote for the fork, then syncing the fork.

### 6. Configure a Remote for the Fork

Next up, you’ll have to specify a new remote upstream repository for us to sync with the fork. This will be the original repository that you forked from. you’ll have to do this with the git remote add command.

##### ` git remote add upstream https://github.com/sujata13/HacktoberFest-2020 `

In this example, // upstream // is the shortname we have supplied for the remote repository since in terms of Git, “upstream” refers to the repository that you cloned from. If you want to add a remote pointer to the repository of a collaborator, you may want to provide that collaborator’s username or a shortened nickname for the shortname.

### 7. Sync the Fork

Once you have configured a remote that references the upstream and original repository on GitHub, you are ready to sync your fork of the repository to keep it up-to-date.
To sync your fork, from the directory of your local repository in a terminal window, you’ll have to use the // git fetch // command to fetch the branches along with their respective commits from the upstream repository. Since you used the shortname “upstream” to refer to the upstream repository, you’ll have to pass that to the command:

##### ` git fetch upstream `

Switch to the local master branch of our repository:

##### ` git checkout master `

Now merge any changes that were made in the original repository’s master branch, that you will access through your local upstream/master branch, with your local master branch:

##### ` git merge upstream/master `

### 8. Create Pull Request

At this point, you are ready to make a pull request to the original repository.

Navigate to your forked repository, and press the “New pull request” button on your left-hand side of your Repo page.

# Hurray! You just got closer to completing your Hacktoberfest challenge.

