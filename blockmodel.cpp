#include <QDebug>
#include "blockmodel.h"
#include "blocks/abstractblock.h"

BlockModel::BlockModel(QObject *parent) : QAbstractListModel(parent)
{

}

BlockModel::~BlockModel()
{
	clear();
}

int BlockModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return mItems.count();
}

QVariant BlockModel::data(const QModelIndex &index, int role) const
{
	if (index.row() < 0 || index.row() >= mItems.count())
		return QVariant();

	int itemRow = index.row();

	if (role == TypeRole)
		return mItems.at(itemRow)->blockType();
	else if (role == ItemsCountRole)
		return mItems.count();
	else if (role == ChildrenCountRole)
		return mItems.at(itemRow)->childrenCount();
	else if (role == ChildrenOneModel)
		return QVariant::fromValue(mItems.at(itemRow)->children().at(0));
	else if (role == ChildrenTwoModel)
		return QVariant::fromValue(mItems.at(itemRow)->children().at(1));
	else if (role == StatusStringRole)
		return QVariant::fromValue(mItems.at(itemRow)->statusString());
	else if (role == PropertyMapRole)
		return mItems.at(itemRow)->getPropertyMap();

	return QVariant::fromValue(mItems.at(itemRow)->getPropertyNames());
}

bool BlockModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
	qDebug() << value << " : " << roleNames()[role] << " " << value.toMap();

	if (index.row() < 0 || index.row() >= mItems.count())
		return false;

	qDebug() << mItems.at(index.row())->getPropertyMap();
	if (role == PropertyMapRole) {
		mItems.at(index.row())->setPropertyMap(value.toMap());
	}
	emit dataChanged(index,index);
	return true;
}

Qt::ItemFlags BlockModel::flags(const QModelIndex &index) const
{
	if (!index.isValid())
		return Qt::ItemIsEnabled;

	return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

bool BlockModel::removeRow(int row, const QModelIndex &parent)
{
	return removeRows(row, 1, parent);
}

bool BlockModel::removeRows(int row, int count, const QModelIndex &parent)
{
	if (count == 0 || mItems.isEmpty())
		return true;
	//if (count < 0 || row + count < mItems)
	beginRemoveRows(parent, row, row + count - 1);
	for (int i = row; i < row + count; ++i)
	{
		AbstractBlock *item = mItems.takeAt(row);
		delete item;
	}
	endRemoveRows();
	return true;
}

void BlockModel::clear()
{
	if (mItems.isEmpty())
		return;
	removeRows(0, mItems.count());
}

QString BlockModel::toString(int indent)
{
	QString res;
	for (auto block : mItems) {
		res += block->toString(indent).append("\n");
	}
	return res;
}

QHash<int, QByteArray> BlockModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[TypeRole] = "blockType";
	roles[ItemsCountRole] = "itemsCount";
	roles[ChildrenCountRole] = "childrenCount";
	roles[PropertyNamesRole] = "propertyNames";
	roles[PropertyMapRole] = "propertyMap";
	roles[StatusStringRole] = "statusString";
	roles[ChildrenOneModel] = "childrenOneModel";
	roles[ChildrenTwoModel] = "childrenTwoModel";

//    int roleStartIdx = FixedRolesEnd;
//    for (int i = roleStartIdx, t = 0; i < roleStartIdx + m_roles.count(); i++, t++)
//        roles[i] = m_roles.at(t).toLatin1();

//	qDebug() << "Returned" << roles.count() << "roles";

	return roles;
}
QList<AbstractBlock *> BlockModel::items() const
{
	return mItems;
}

void BlockModel::setItems(const QList<AbstractBlock *> &items)
{
	mItems = items;
}


