/* FUN_8016257c
 * image   ovl_008900e (ovl), base 0x80161cf0
 * address 0x8016257c  body 0x8016257c..0x80162767  size 492 B
 * body sha256 e074a91ba1be78754977b3d7ae5e213b2bedc68aa0495e3ea93f8a803cc29307
 * provider record sha256 74a7869e4f4cdad9e9eb13d071160a0368b3a449084762eafe19dcaa2c8e2c74
 * callees 3 direct (3 in corpus)
 * provider Ghidra 12.2
 */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_8016257c(uint *param_1)

{
  byte bVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_18 [8];
  
  uVar4 = param_1[0x82];
  uVar5 = param_1[0x8d];
  func_0x80082200(auStack_18,0,8);
  bVar1 = *(byte *)((int)param_1 + 0x2b7);
  if (bVar1 == 1) {
    *(uint *)(uVar4 + 0x14) = uVar5 + 0x33c;
    *(undefined2 *)((int)param_1 + 0x1f6) = 0;
    *param_1 = *param_1 | 10;
    *(char *)((int)param_1 + 0x2b7) = *(char *)((int)param_1 + 0x2b7) + '\x01';
LAB_8016267c:
    sVar2 = *(short *)((int)param_1 + 0x1f6) + 1;
    if (0x6f < *(short *)((int)param_1 + 0x1f6)) goto LAB_8016271c;
    *(short *)((int)param_1 + 0x1f6) = sVar2;
    if (sVar2 < 0x10) {
      *(char *)(uVar4 + 0x18) = (char)((_DAT_800c76b0 >> 0x18) * (sVar2 + 1) >> 4);
      *(char *)(uVar4 + 0x19) =
           (char)((_DAT_800c76b0 >> 0x10 & 0xff) * (*(short *)((int)param_1 + 0x1f6) + 1) >> 4);
      *(char *)(uVar4 + 0x1a) =
           (char)((_DAT_800c76b0 >> 8 & 0xff) * (*(short *)((int)param_1 + 0x1f6) + 1) >> 4);
    }
    sVar2 = *(short *)(uVar4 + 6) + 4;
    *(short *)(uVar4 + 4) = *(short *)(uVar4 + 4) + 4;
  }
  else {
    if (1 < bVar1) {
      if (bVar1 != 2) goto LAB_8016271c;
      goto LAB_8016267c;
    }
    if (bVar1 != 0) goto LAB_8016271c;
    iVar3 = 9000 - ((int)*(short *)((int)param_1 + 0x25e) - *(int *)(uVar5 + 0x50));
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    *(short *)(uVar4 + 4) = (short)((int)((uint)*(ushort *)(param_1 + 0xae) * iVar3) / 9000);
    sVar2 = (short)((int)((uint)*(ushort *)((int)param_1 + 0x2ba) * iVar3) / 9000);
  }
  *(short *)(uVar4 + 6) = sVar2;
LAB_8016271c:
  if ((0 < *(short *)((int)param_1 + 0x1f2)) && (uVar4 = func_0x80033604(), (uVar4 & 0x1f) == 0)) {
    func_0x80037780(0x150800,0,uVar5 + 0xd70,auStack_18);
  }
  return;
}
