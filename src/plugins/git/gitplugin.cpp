#include <utils/utilsicons.h>
    const QString prefix = "git";
    Utils::MimeDatabase::addMimeTypes(RC_GIT_MIME_XML);
        if (!DocumentManager::saveModifiedDocumentSilently(document))
    m_gitClient->revert({ state.currentFile() }, revertStaging);
        : IconItemDelegate(widget, Utils::Icons::UNDO.imageFileName())
    if (m_gitClient->beginStashScope(topLevel, "Rebase-i"))
    m_gitClient->synchronousReset(state.currentFileTopLevel(), { state.relativeCurrentFile() });
     *  m_gitClient->launchGitK(dir.currentFileDirectory(), ".");
    if (QFileInfo(dir,".git").exists() || dir.cd(".git")) {
        if (!m_gitClient->beginStashScope(m_submitRepository, "Rebase-fixup",
            currentBranch.prepend("branch.");
            currentBranch.append(".rebase");
            rebase = (m_gitClient->readConfigValue(topLevel, currentBranch) == "true");
    if (!m_gitClient->beginStashScope(topLevel, "Pull", rebase ? Default : AllowUnstashed))
        m_gitClient->synchronousMerge(state.topLevel(), "--abort");
        m_gitClient->rebase(state.topLevel(), "--abort");
        m_gitClient->synchronousCherryPick(state.topLevel(), "--abort");
        m_gitClient->synchronousRevert(state.topLevel(), "--abort");
        m_gitClient->rebase(state.topLevel(), "--continue");
        m_gitClient->cherryPick(state.topLevel(), "--continue");
        m_gitClient->revert(state.topLevel(), "--continue");
    if (!m_gitClient->beginStashScope(workingDirectory, "Apply-Patch", AllowUnstashed))
    QString output = "## master...origin/master [ahead 1]\n";
    output += QString::fromLatin1(QTest::currentDataTag()) + " main.cpp\n";