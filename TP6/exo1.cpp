#include "tp6.h"
#include <QApplication>
#include <time.h>

MainWindow* w = nullptr;

void Graph::buildFromAdjenciesMatrix(int **adjacencies, int nodeCount)
{
    for (int currentIndex = 0; currentIndex < nodeCount; currentIndex++) {
        GraphNode* node = new GraphNode(currentIndex);
        this->appendNewNode(node);
    }

    for (int startIndex = 0; startIndex < nodeCount; startIndex++) {
        for (int EndIndex = 0; EndIndex < nodeCount; EndIndex++) {
            if (adjacencies[startIndex][EndIndex] != 0) {
                GraphNode* startNode = nodes[startIndex];
                GraphNode* EndNode = nodes[EndIndex];
                startNode->appendNewEdge(EndNode);
            }
        }
    }
}

void Graph::deepTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
    // Changer le booléen visited à true pour le noeud actuel
    visited[first->value] = true;
    nodes[nodesSize++] = first;

    Edge* edge = first->edges;
    while (edge != nullptr) {
        GraphNode* destination = edge->destination;
        if (!visited[destination->value]) {
            deepTravel(destination, nodes, nodesSize, visited);
        }
        edge = edge->next;
    }
}

void Graph::wideTravel(GraphNode *first, GraphNode *nodes[], int &nodesSize, bool visited[])
{
	std::queue<GraphNode*> nodeQueue;
    nodeQueue.push(first);

    while (!nodeQueue.empty()) {
        GraphNode* current = nodeQueue.front();
        nodeQueue.pop();

        visited[first->value] = true;
        nodes[nodesSize++] = first;

        Edge* edge = current->edges;
        while (edge != nullptr) {
            GraphNode* destination = edge->destination;
            if (!visited[destination->value]) {
				visited[destination->value] = true;
				nodes[nodesSize++] = destination;
                nodeQueue.push(destination);
            }
			edge = edge->next;
        }
    }
}

bool Graph::detectCycle(GraphNode *first, bool visited[])
{
    visited[first->value] = true;

    Edge* edge = first->edges;
    while (edge != nullptr) {
        GraphNode* destination = edge->destination;
        if (visited[destination->value]) {
			return true;
        } else {
			if (detectCycle(destination, visited)){
				return true;
			}
        }
        edge = edge->next;
    }
    return false;
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 150;
	w = new GraphWindow();
	w->show();

	return a.exec();
}
