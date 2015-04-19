#include "blockmodel.h"
#include "blocks/abstractblock.h"

BlockModel::BlockModel(QObject *parent)
{

}

BlockModel::~BlockModel()
{

}

int BlockModel::rowCount(const QModelIndex &parent) const
{
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

	return QVariant::fromValue(mItems.at(itemRow)->getPropertyNames());
}

QHash<int, QByteArray> BlockModel::roleNames() const
{
	QHash<int, QByteArray> roles;
	roles[TypeRole] = "blockType";
	roles[ItemsCountRole] = "itemsCount";
	roles[ChildrenCountRole] = "childrenCount";
	roles[PropertyNamesRole] = "propertyNames";
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


