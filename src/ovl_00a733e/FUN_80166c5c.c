/* FUN_80166c5c
 * image   ovl_00a733e (ovl), base 0x80161cf0
 * address 0x80166c5c  body 0x80166c5c..0x80166eeb  size 656 B
 * body sha256 e0c25213ba885420e4bcf53276dd829de5d94a3f38fbec65047c57efd1f1ae01
 * provider record sha256 05569333b345f10f52e46bf95eecf42f93c0b9f142ceedfe75d99ada7ef740f1
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_80166c5c(int param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  
  if (*(char *)(param_1 + 5) == '\0') {
    *(undefined1 *)(param_1 + 5) = 1;
    *(undefined2 *)(param_1 + 0x1f2) = 0xffff;
    *(byte *)(param_1 + 0x25c) = *(byte *)(param_1 + 0x25c) | 1;
    *(uint *)(param_1 + 0x1e8) =
         (*(byte *)(*(int *)(param_1 + 0x250) + 0x1e9) - 1) * 0x10000 + 0x6000f00;
    func_0x80052bd0(8,0);
    func_0x80052c6c(0x14,0xfa,4);
    func_0x80052d10(0x23,0xfa,0x3c,0x18);
    func_0x80052bd0(3,0x1e);
    func_0x80052bd0(2,0x28);
    func_0x80052bd0(3,0x3c);
    func_0x80052c6c(8,0xfa,0x3c);
    func_0x80052c6c(0x23,0x50,0x44);
    func_0x80052bd0(2,0x44);
    func_0x80052bd0(2,0x4b);
    func_0x80052bd0(3,0x50);
    func_0x80052bd0(3,100);
    func_0x80052c6c(6,0xfa,100);
    func_0x80052bd0(2,0x6a);
    func_0x80052c6c(8,0xfa,0x6e);
    func_0x80052d10(0x3c,0xfa,0,0x76);
  }
  else if (*(char *)(param_1 + 5) != '\x01') goto LAB_80166e04;
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x800;
  func_0x8003331c(param_1,param_2,param_3,0);
  *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x800;
  cVar1 = func_0x80089d54(param_1,param_2,param_3,0x100);
  *(char *)(param_1 + 5) = *(char *)(param_1 + 5) + cVar1;
LAB_80166e04:
  if ((**(uint **)(param_1 + 0x214) & 0x10000) != 0) {
    FUN_80167374(param_1,8,0);
    *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) =
         *(uint *)(*(int *)(param_1 + 0x234) + 0xbc0) & 0xfffffffe;
    uVar3 = 0xf;
    if ((*(byte *)(param_1 + 8) & 1) != 0) {
      iVar2 = 0x1608;
      do {
        uVar3 = uVar3 + 1;
        puVar4 = (uint *)(*(int *)(param_1 + 0x234) + iVar2);
        *puVar4 = *puVar4 & 0xfffffffe;
        iVar2 = iVar2 + 0x178;
      } while (uVar3 < 0x13);
    }
    puVar4 = *(uint **)(param_1 + 0x234);
    puVar4[0x4c] = 0x40;
    puVar4[0x4d] = 0x101020;
    *puVar4 = *puVar4 | 0x80;
    iVar2 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar2 + 0xd38) = *(uint *)(iVar2 + 0xd38) | 0x80;
    *(undefined4 *)(iVar2 + 0xe68) = 0x40;
    *(undefined4 *)(iVar2 + 0xe6c) = 0x101020;
    iVar2 = *(int *)(param_1 + 0x234);
    *(uint *)(iVar2 + 0x1318) = *(uint *)(iVar2 + 0x1318) | 0x80;
    *(undefined4 *)(iVar2 + 0x1448) = 0x40;
    *(undefined4 *)(iVar2 + 0x144c) = 0x101020;
  }
  return;
}
