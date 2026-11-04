/* FUN_80162e00
 * image   ovl_008bef8 (ovl), base 0x80161cf0
 * address 0x80162e00  body 0x80162e00..0x80162fdb  size 476 B
 * body sha256 bbe80776a7f573895b16f0c19785e36e1116f045ccc1729bc03c2402430c67f1
 * provider record sha256 3726240506697fc063534afd3c815d390ae54b1a80c6986bf034c19e66b2101e
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80162e00(int param_1)

{
  short sVar1;
  
  switch(*(undefined1 *)(param_1 + 0x2c0)) {
  default:
    goto switchD_80162e30_caseD_0;
  case 1:
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
  case 2:
    sVar1 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar1;
    sVar1 = FUN_801635d0(4,(int)sVar1,0x14);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar1;
    sVar1 = FUN_801635d0(4,(int)*(short *)(param_1 + 500),0xffffff9c);
    break;
  case 3:
    sVar1 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar1;
    sVar1 = FUN_80163698(4,(int)sVar1,0x14);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar1;
    sVar1 = FUN_80163698(4,(int)*(short *)(param_1 + 500),0xffffff9c);
    break;
  case 4:
    sVar1 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar1;
    sVar1 = FUN_801635d0(3,(int)sVar1,0xffffffec);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar1;
    sVar1 = FUN_801635d0(3,(int)*(short *)(param_1 + 500),100);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar1;
    if (*(short *)(param_1 + 500) == 3) {
      *(undefined2 *)(param_1 + 500) = 0;
      *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
    }
    goto LAB_80162fc4;
  case 5:
    sVar1 = *(short *)(param_1 + 500) + 1;
    *(short *)(param_1 + 500) = sVar1;
    sVar1 = FUN_80163698(3,(int)sVar1,0xffffffec);
    *(short *)(param_1 + 0x2c6) = *(short *)(param_1 + 0x2c6) + sVar1;
    sVar1 = FUN_80163698(3,(int)*(short *)(param_1 + 500),100);
    *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar1;
    if (*(short *)(param_1 + 500) == 3) {
      *(undefined2 *)(param_1 + 500) = 0;
      *(undefined1 *)(param_1 + 0x2c0) = 0;
    }
LAB_80162fc4:
    FUN_80162fdc(param_1);
    goto switchD_80162e30_caseD_0;
  }
  *(short *)(param_1 + 0x2c4) = *(short *)(param_1 + 0x2c4) + sVar1;
  if (*(short *)(param_1 + 500) == 4) {
    *(undefined2 *)(param_1 + 500) = 0;
    *(char *)(param_1 + 0x2c0) = *(char *)(param_1 + 0x2c0) + '\x01';
  }
switchD_80162e30_caseD_0:
  return;
}
