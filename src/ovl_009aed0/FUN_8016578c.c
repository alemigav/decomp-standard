/* FUN_8016578c
 * image   ovl_009aed0 (ovl), base 0x80161cf0
 * address 0x8016578c  body 0x8016578c..0x801659c7  size 572 B
 * body sha256 4012644992e98133103402c6d9aa4af83345ef1789d0ab89aa1bd2dd7986faec
 * provider record sha256 4f373764e9edfe104c01b11d2b4977bd0feef029250516c91500c886a75f7bec
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
void FUN_8016578c(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  
  iVar3 = *(int *)(param_1 + 0x234);
  local_1e = 0xfed4;
  local_1c = 0;
  bVar1 = *(byte *)(param_1 + 6);
  if (bVar1 != 1) {
    if (1 < bVar1) {
      if (bVar1 != 2) {
        return;
      }
      func_0x80089d54(param_1,param_2,param_3,0x1000);
      if (*(char *)(param_1 + 0x1e9) == 'l') {
        *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
      }
      sVar2 = *(short *)(param_1 + 0x1f6) + 1;
      *(short *)(param_1 + 0x1f6) = sVar2;
      if (sVar2 == 2) {
        local_20 = 0xfa;
        if (*(short *)(param_1 + 500) == 0) {
          local_20 = 0xff06;
        }
        *(undefined2 *)(param_1 + 0x1f6) = 0;
        *(ushort *)(param_1 + 500) = *(ushort *)(param_1 + 500) ^ 1;
      }
      if (*(byte *)(param_1 + 0x1e9) < 0x50) {
        iVar3 = iVar3 + 0x38;
        func_0x80037780(0x32000,0,iVar3,&local_20);
        func_0x80037780(0x62000,0,iVar3,&local_20);
      }
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
      func_0x8003331c(param_1,param_2,param_3,0);
      *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
      return;
    }
    if (bVar1 != 0) {
      return;
    }
    iVar3 = iVar3 + 0x38;
    *(undefined2 *)(param_1 + 500) = 0;
    *(undefined2 *)(param_1 + 0x1f6) = 0;
    local_20 = 0xfa;
    func_0x80037780(0x62300,0,iVar3,&local_20);
    func_0x80037780(0x62300,0,iVar3,&local_20);
    local_20 = 0xfa;
    func_0x80037780(0x62300,0x800,iVar3,&local_20);
    func_0x80037780(0x62300,0x800,iVar3,&local_20);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  }
  *(undefined4 *)(param_1 + 0x1e8) = 0;
  func_0x80089d54(param_1,param_2,param_3,0x1000);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
  func_0x8003331c(param_1,param_2,param_3,0);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
  *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + '\x01';
  return;
}
