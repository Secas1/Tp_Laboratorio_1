typedef struct
{
    int id;
    char name [51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int initEmployees(eEmployee list[],int len);
/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastname[] char
 * \param salary float
 * \param sector int
 * \return int
 *
 */
int addEmployee(eEmployee list[],int len,int id,char name[],char lastname[],float salary,int sector);
/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return int
 *
 */
int findEmployeeById(eEmployee list[],int len,int id);
/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \param id int
 * \return int
 *
 */
int removeEmployee(eEmployee list[],int len,int id);
/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \param order int
 * \return int
 *
 */
int sortEmployees(eEmployee list[],int len,int order);
/** \brief
 *
 * \param list[] eEmployee
 * \param len int
 * \return int
 *
 */
int printEmployees(eEmployee list[],int len);
