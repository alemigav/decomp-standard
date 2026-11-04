/* FUN_801650ac
 * image   ovl_0093aba (ovl), base 0x80161cf0
 * address 0x801650ac  body 0x801650ac..0x8016535b  size 688 B
 * body sha256 023d32c57e865cf15b2b879e0db018a8544466efb9fc96b8af7aa294fa0c1936
 * provider record sha256 93f98a815774507b4b34153b61850c8ff04969f9fa40c08e254d583210f69145
 * callees 6 direct (6 in corpus)
 * provider Ghidra 12.2
 */
void FUN_801650ac(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  uint *puVar3;
  int iVar4;
  
  switch(*(undefined1 *)(param_1 + 6)) {
  case 0:
    *(undefined4 *)(param_1 + 0x1e8) = 0x700;
    *(undefined1 *)(param_1 + 6) = 1;
    func_0x80077adc(0x4000001,param_1 + 0x28);
  case 1:
    func_0x80089d54(param_1,param_2,param_3,0x200);
    return;
  case 2:
    *(undefined4 *)(param_1 + 0x1e8) = 0x4000700;
    *(undefined1 *)(param_1 + 6) = 3;
    *(byte *)(param_1 + 0x26f) = *(byte *)(param_1 + 0x26f) & 0x7f;
  case 3:
    iVar4 = func_0x80089d54(param_1,param_2,param_3,0x100);
    if (iVar4 == 0) {
      return;
    }
    *(undefined4 *)(param_1 + 4) = 0x1000000;
    return;
  case 4:
    puVar3 = *(uint **)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x1000f00;
    *(undefined1 *)(param_1 + 6) = 5;
    *(undefined1 *)(param_1 + 0x25c) = 1;
    puVar3[0x4c] = 0x40;
    puVar3[0x4d] = 0x101010;
    *puVar3 = *puVar3 | 0x80;
    break;
  case 5:
  case 7:
    break;
  case 6:
    iVar4 = *(int *)(param_1 + 0x234);
    *(undefined4 *)(param_1 + 0x1e8) = 0x2000f00;
    *(undefined1 *)(param_1 + 6) = 7;
    *(uint *)(iVar4 + 0xbc0) = *(uint *)(iVar4 + 0xbc0) | 0x80;
    *(undefined4 *)(iVar4 + 0xcf0) = 0x40;
    *(undefined4 *)(iVar4 + 0xcf4) = 0x101010;
    break;
  case 8:
    *(undefined4 *)(param_1 + 0x1e8) = 0x3000f00;
    *(undefined1 *)(param_1 + 6) = 9;
    iVar4 = *(int *)(param_1 + 0x234) + 0xbf8;
    func_0x80037780(0x213e8,(int)*(short *)(param_1 + 0x66),iVar4,0);
    func_0x80037780(0x21000,(int)((*(ushort *)(param_1 + 0x66) + 0x800) * 0x10000) >> 0x10,iVar4,0);
  case 9:
    iVar4 = *(int *)(param_1 + 0x234);
    if ((*(byte *)(param_1 + 0x1e9) < 0xf) && ((*(byte *)(param_1 + 0x1e9) & 1) == 0)) {
      uVar1 = func_0x80033604();
      func_0x80037780((uVar1 & 0xff) * 8 + 0x400,(int)*(short *)(param_1 + 0x66),iVar4 + 0xbf8,0);
    }
    cVar2 = *(char *)(param_1 + 0x1e9);
    if (((cVar2 == '-') || (cVar2 == '0')) || (cVar2 == '\x05')) {
      func_0x80037780(0x21000,(int)*(short *)(param_1 + 0x66),iVar4 + 0xbf8,0);
    }
    func_0x800334c8(param_1,param_2,param_3,0);
    cVar2 = func_0x80089d54(param_1,param_2,param_3,0x100);
    *(char *)(param_1 + 6) = *(char *)(param_1 + 6) + cVar2;
    func_0x80032b5c(param_1,0);
    return;
  case 10:
    *(undefined4 *)(param_1 + 4) = 0x7000000;
  default:
    goto switchD_801650f4_default;
  }
  func_0x80089d54(param_1,param_2,param_3,0x100);
switchD_801650f4_default:
  return;
}
