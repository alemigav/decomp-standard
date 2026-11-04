/* FUN_800612a8
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800612a8  body 0x800612a8..0x800615c7  size 800 B
 * body sha256 07e45a92a6aa134cfdd32b4957aab2868cccd71560801f06e70467458de49418
 * provider record sha256 87e31f439fd74737c79270301919e2ed78aa14f4cf5571984fcced8392ad7a6d
 * callees 4 direct (4 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800612a8(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  char cVar2;
  ushort uVar3;
  short local_28 [8];
  
  local_28[0] = 0;
  local_28[1] = 0x12;
  local_28[2] = 0xc;
  local_28[3] = 0;
  local_28[4] = 0xf;
  if (*(char *)(param_1 + 7) == '\0') {
    *(undefined1 *)(param_1 + 7) = 1;
    *(int *)(param_1 + 0x1e8) = local_28[*(ushort *)(param_1 + 0x1f0) >> 0xd] * 0x1000000 + 0x700;
    DAT_800e112a = DAT_800e112a | 0x18;
  }
  if ((param_4 & 0x100) == 0) {
    *(undefined2 *)(param_1 + 6) = 0x300;
    return;
  }
  uVar3 = *(ushort *)(param_1 + 0x1aa) & 0xfff;
  if ((uVar3 != 0xe) && (uVar3 != 0x12)) {
    if ((((param_4 & 0x10) != 0) || ('\x19' < DAT_800df8c1)) &&
       ((*(ushort *)(param_1 + 0x1f0) & 0x8000) == 0)) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x8000;
      return;
    }
    if ((((param_4 & 0x20) != 0) || (DAT_800df8c1 < -0x19)) &&
       ((*(ushort *)(param_1 + 0x1f0) & 0x2000) == 0)) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x2000;
      return;
    }
    if ((((param_4 & 0x30) == 0) && (DAT_800df8c1 < '\x1a')) &&
       ((-0x1a < DAT_800df8c1 && ((*(ushort *)(param_1 + 0x1f0) & 0x4000) == 0)))) {
      *(undefined1 *)(param_1 + 7) = 0;
      *(ushort *)(param_1 + 0x1f0) = *(ushort *)(param_1 + 0x1f0) & 0x1fff | 0x4000;
      return;
    }
  }
  if (((DAT_800e8b58 & 1) == 0) && ((DAT_800df90e & 4) != 0)) {
    *(undefined2 *)(param_1 + 6) = 0x500;
  }
  if ((param_4 & 0x40) != 0) {
    iVar1 = FUN_8008cce4(*(ushort *)(param_1 + 0x1aa) & 0xfff);
    if (iVar1 != 0) {
      *(undefined2 *)(param_1 + 6) = 0x200;
      return;
    }
    if ((DAT_800df918 & 0x40) != 0) {
      cVar2 = FUN_8008d00c();
      if (cVar2 == '\0') {
        FUN_80077adc(0x1010001,param_1 + 0x28);
      }
      else {
        *(undefined2 *)(param_1 + 6) = 0x400;
      }
    }
  }
  cVar2 = DAT_800df8c0;
  if (((param_4 & 8) != 0) || (DAT_800df8c0 < -0x19)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -0x40;
  }
  if (((param_4 & 2) != 0) || ('\x19' < cVar2)) {
    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + 0x40;
  }
  FUN_80089d54(param_1,param_2,param_3,0x200);
  return;
}
