/* FUN_800ac394
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800ac394  body 0x800ac394..0x800ac613  size 640 B
 * body sha256 4a5785436722eeb8955149b70e4c96267376da5e658ed1dbb4f317f228bbe748
 * provider record sha256 2c083023c652876ef2860d3a110d0e065c6931e125b6a8dfcfeaef16f1652f80
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
uint FUN_800ac394(int param_1,char *param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int unaff_s1;
  char *pcVar7;
  uint uVar8;
  
  uVar8 = 0;
  uVar6 = 0;
  if (param_2[0x10] != '\0') {
    pcVar7 = param_2;
    do {
      cVar1 = *pcVar7;
      if (((((cVar1 == -0x80) || (cVar1 == '\x01')) || (cVar1 == '\n')) ||
          ((cVar1 == -0x60 || (cVar1 == -0x5f)))) || ((cVar1 == -0x7d || (cVar1 == -0x7c)))) {
        if (cVar1 == -0x60) {
          iVar4 = (int)*(short *)(param_1 + 0x170) << 1;
        }
        else if (cVar1 == -0x5f) {
          iVar4 = (int)*(short *)(param_1 + 0x17c) << 1;
        }
        else {
          uVar3 = FUN_800ac0c8(cVar1,*(undefined1 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b)
                              );
          iVar4 = (uVar3 & 0xffff) - 0x2000;
        }
        iVar5 = iVar4 * *(short *)(pcVar7 + 2) >> 8;
        iVar4 = -0x2000;
        if ((-0x2001 < iVar5) && (iVar4 = 0x1fff, iVar5 < 0x2000)) {
          iVar4 = iVar5;
        }
        bVar2 = pcVar7[1];
        if (bVar2 == 1) {
          iVar5 = uVar6 + iVar4 + -0x2000;
          if (iVar5 < -0x2000) {
            iVar4 = -0x2000;
          }
          else {
LAB_800ac51c:
            iVar4 = 0x1fff;
            if (iVar5 < 0x2000) {
              iVar4 = iVar5;
            }
          }
LAB_800ac530:
          uVar6 = iVar4 + 0x2000;
          unaff_s1 = iVar4;
        }
        else if (bVar2 < 2) {
          uVar6 = unaff_s1 + 0x2000;
          if (bVar2 == 0) goto LAB_800ac530;
        }
        else {
          if (bVar2 == 2) {
            iVar5 = (int)((uVar6 - 0x2000) * iVar4) >> 0xd;
            iVar4 = -0x2000;
            if (-0x2001 < iVar5) goto LAB_800ac51c;
            goto LAB_800ac530;
          }
          uVar6 = unaff_s1 + 0x2000;
        }
      }
      else {
        uVar3 = FUN_800ac0c8(cVar1,*(undefined1 *)(param_1 + 0x4a),*(undefined1 *)(param_1 + 0x4b));
        uVar3 = (int)((uVar3 & 0xffff) * (int)*(short *)(pcVar7 + 2)) >> 8;
        if (0x3fff < (int)uVar3) {
          uVar3 = 0x3fff;
        }
        bVar2 = pcVar7[1];
        if (bVar2 == 1) {
          uVar3 = uVar6 + uVar3;
LAB_800ac5b8:
          uVar6 = 0x3fff;
          if (uVar3 < 0x4000) {
            uVar6 = uVar3;
          }
        }
        else if (bVar2 < 2) {
          if (bVar2 == 0) {
            uVar6 = uVar3;
          }
        }
        else if (bVar2 == 2) {
          uVar3 = uVar6 * uVar3 >> 0xe;
          goto LAB_800ac5b8;
        }
      }
      uVar8 = uVar8 + 1;
      pcVar7 = pcVar7 + 4;
    } while (uVar8 < (byte)param_2[0x10]);
  }
  return uVar6 & 0xffff;
}
