#ifndef BLOCKMODEL_H
#define BLOCKMODEL_H

#include <QAbstractListModel>

class AbstractBlock;

class BlockModel : public QAbstractListModel
{
	Q_OBJECT
public:
	enum FixedRoles {
		TypeRole = Qt::UserRole + 1,
		ItemsCountRole,
		ChildrenCountRole,
		ChildrenOneModel,
		ChildrenTwoModel,
		PropertyNamesRole,
		FixedRolesEnd
	};

	BlockModel(QObject *parent = 0);
	~BlockModel();

	Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

	QList<AbstractBlock *> items() const;
	void setItems(const QList<AbstractBlock *> &items);

protected:
	QStringList mRoles;
	QHash<int, QByteArray> roleNames() const;
	QList<AbstractBlock *> mItems;
};

#endif // BLOCKMODEL_H
