/* FUN_8002aee0
 * image   stage2 (stage2), base 0x80018a80
 * address 0x8002aee0  body 0x8002aee0..0x8002afa3  size 196 B
 * body sha256 a583387c65b63478a7166fd0d5f4c44040b9dbbc8136eaa20411b80be9ef63b4
 * provider record sha256 2131c588c9e3ac284ed1570c785fe68e098d982c50724ff5a9e1455ac275429a
 * callees 0 direct (0 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8002aee0(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  *(undefined4 *)(*param_1 + 0x14) = 0x5e;
  (**(code **)(*param_1 + 4))(param_1,1);
  if (*(int *)(param_1[0x5d] + 0x50) != 0) {
    *(undefined4 *)(*param_1 + 0x14) = 0x35;
    (**(code **)*param_1)(param_1);
  }
  iVar2 = 0;
  piVar1 = param_1;
  do {
    iVar2 = iVar2 + 1;
    *(undefined1 *)(piVar1 + 0x2d) = 0;
    *(undefined1 *)(piVar1 + 0x31) = 1;
    *(undefined1 *)(piVar1 + 0x35) = 5;
    piVar1 = (int *)((int)param_1 + iVar2);
  } while (iVar2 < 0x10);
  *(undefined2 *)((int)param_1 + 0xf2) = 1;
  *(undefined2 *)(param_1 + 0x3d) = 1;
  param_1[0x3a] = 0;
  param_1[9] = 0;
  param_1[0x40] = 0;
  param_1[0x3b] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  param_1[0x3e] = 0;
  *(undefined1 *)(param_1 + 0x3f) = 0;
  *(undefined4 *)(param_1[0x5d] + 0x50) = 1;
  return;
}
