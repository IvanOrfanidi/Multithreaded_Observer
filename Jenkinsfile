pipeline {
    agent any
    stages {
        stage('submodule update') {
            steps {
                sh 'git submodule init'
                sh 'git submodule update'
            }
        }

        stage('build') {
            steps {
                sh 'bash compile.sh'
            }
        }
        
        stage('cppcheck') {
            steps {
                sh 'cppcheck --enable=all --xml --xml-version=2 -i ext  source include 2> build/cppcheck.xml'
                sh 'cppcheck-htmlreport --source-encoding="iso8859-1" --title="project" --source-dir=. --report-dir=build --file=build/cppcheck.xml'
                publishHTML(
                    target: [
                      allowMissing: true,
                      alwaysLinkToLastBuild: false,
                      keepAll: false,
                      reportDir: 'build',
                      reportFiles: 'index.html',
                      reportName: 'CppCheck Report',
                      reportTitles: ''
                    ]
                )
            }
        }

        stage('run tests') {
            steps {
                sh 'build/multithreaded_observer_test'
            }
        }

        stage('clean') {
            steps {
                cleanWs()
            }
        }
    }
}
