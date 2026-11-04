/* FUN_8000bd80
 * image   boot (boot), base 0x80000480
 * address 0x8000bd80  body 0x8000bd80..0x8000be27  size 168 B
 * body sha256 73aa7c5372b7ba241f8899887fe65abf396f33e736aa3c0eac8fadc57e063304
 * provider record sha256 9617b2b62bb39e14ebf0ee39b89b2935ccddb451511132e99fcf45ae0dcfd602
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_8000bd80(undefined2 *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (_DAT_800128f0 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar2 = 0xc;
    if (param_3 == 0) {
      uVar2 = 0xb;
    }
    *param_1 = uVar2;
    *(char *)(param_1 + 1) = (char)param_2;
    *(undefined4 *)(param_1 + 2) = param_7;
    *(undefined4 *)(param_1 + 4) = param_5;
    *(undefined4 *)(param_1 + 6) = param_4;
    *(undefined4 *)(param_1 + 8) = param_6;
    *(undefined4 *)(param_1 + 10) = 0;
    if (param_2 == 1) {
      uVar1 = FUN_8000be30();
      uVar1 = FUN_80007450(uVar1,param_1,0);
    }
    else {
      uVar1 = FUN_8000be30();
      uVar1 = osSendMesg(uVar1,param_1,0);
    }
  }
  return uVar1;
}
