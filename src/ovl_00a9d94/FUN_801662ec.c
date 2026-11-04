/* FUN_801662ec
 * image   ovl_00a9d94 (ovl), base 0x80161cf0
 * address 0x801662ec  body 0x801662ec..0x801664d7  size 492 B
 * body sha256 6e2889481f157e023273045c8d0bec7988a4746f1db592e1ff646a5da31294ef
 * provider record sha256 a9a1f0e044e7774892f966c1eb7575d987915bba3019c506c19b4b001296cfb0
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801662ec(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x17000000;
    func_0x80089d54(param_1,param_2,param_3,0x100);
    if ((*(ushort *)(param_1 + 0x270) & 1) != 0) {
      *(undefined1 *)(param_1 + 6) = 1;
      *(undefined1 *)(*(int *)(param_1 + 0x208) + 0xe) = 7;
      *(ushort *)(param_1 + 0x1aa) = *(ushort *)(param_1 + 0x1aa) & 0xbfff;
    }
    *(undefined2 *)(param_1 + 0x1e0) = 0;
    *(undefined2 *)(param_1 + 0x1e2) = 0;
    *(undefined2 *)(param_1 + 0x1e4) = 0;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined1 *)(param_1 + 0x1a2) = 0;
    break;
  case 1:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
  case 2:
    iVar1 = (*(ushort *)(param_1 + 0x1e2) + 0x1e) - (uint)*(ushort *)(param_1 + 500);
    *(short *)(param_1 + 0x1e2) = (short)iVar1;
    iVar1 = *(int *)(param_1 + 0x2c) + (iVar1 * 0x10000 >> 0x10);
    *(int *)(param_1 + 0x2c) = iVar1;
    *(short *)(param_1 + 500) = *(short *)(param_1 + 500) + -1;
    if (*(short *)(param_1 + 0x25e) < iVar1) {
      *(int *)(param_1 + 0x2c) = (int)*(short *)(param_1 + 0x25e);
      *(undefined1 *)(param_1 + 6) = 3;
      *(undefined4 *)(param_1 + 0x1e8) = 0x19050300;
      func_0x800334c8(param_1,param_2,param_3,0);
    }
    break;
  case 3:
    func_0x800334c8(param_1,param_2,param_3,0);
    uVar3 = 0x400;
    goto LAB_80166488;
  case 4:
    *(undefined4 *)(param_1 + 0x1e8) = 0x9000700;
    *(undefined1 *)(param_1 + 6) = 5;
  case 5:
    func_0x800334c8(param_1,param_2,param_3,0);
    uVar3 = 0x200;
LAB_80166488:
    cVar2 = func_0x80089d54(param_1,param_2,param_3,uVar3);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    break;
  case 6:
    *(undefined4 *)(param_1 + 4) = 0x1010000;
    *(undefined1 *)(param_1 + 0x2ba) = 0x1e;
  }
  return;
}
