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
		PropertyMapRole,
		StatusStringRole,
		FixedRolesEnd
	};

	explicit BlockModel(QObject *parent = 0);
	~BlockModel();

	Q_INVOKABLE int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	bool setData(const QModelIndex &index, const QVariant &value, int role);
	Qt::ItemFlags flags(const QModelIndex &index) const;
	Q_INVOKABLE bool removeRow(int row, const QModelIndex &parent = QModelIndex());
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
	void clear();

	QString toString(int indent = 0);

	QList<AbstractBlock *> items() const;
	void setItems(const QList<AbstractBlock *> &items);

protected:
	QStringList mRoles;
	QHash<int, QByteArray> roleNames() const;
	QList<AbstractBlock *> mItems;
};

#endif // BLOCKMODEL_H
