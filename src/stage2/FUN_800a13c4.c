/* FUN_800a13c4
 * image   stage2 (stage2), base 0x80018a80
 * address 0x800a13c4  body 0x800a13c4..0x800a15cf  size 524 B
 * body sha256 5e6aaa00043dfcd53cd29abeb84538589bce28de20c7c4565032ed70652fcb62
 * provider record sha256 e237da721a370ca5c0f7a04e4cdf8c5101004952f1731028392f6d6b315f4b07
 * callees 1 direct (1 in corpus)
 * provider Ghidra 12.2
 */
void FUN_800a13c4(undefined1 param_1,undefined2 param_2,uint param_3,byte param_4)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar4 = 0;
  puVar5 = (uint *)&DAT_8013bc90;
  while ((*(char *)((int)puVar5 + 0xfc1) != '\0' || (*puVar5 != (param_3 & 0x7fffffff)))) {
    uVar4 = uVar4 + 1;
    puVar5 = puVar5 + 0x3fe;
    if (7 < uVar4) {
      uVar4 = 0xffffffff;
LAB_800a1434:
      if (uVar4 != 0xffffffff) {
        if ((int)uVar4 < 0) {
          uVar6 = uVar4 & 0x7fffffff;
          param_4 = param_4 & 0xf;
          if (param_4 == 1) {
            *(undefined4 *)((uVar4 * 0x200 - uVar6) * 8 + -0x7fec3380) = 0;
          }
          else if (param_4 < 2) {
            if (param_4 == 0) {
              *(undefined1 *)((uVar4 * 0x200 - uVar6) * 8 + -0x7fec3390) = param_1;
            }
          }
          else {
            if (param_4 == 2) {
              iVar2 = (uVar4 * 0x200 - uVar6) * 8;
              *(undefined1 *)(iVar2 + -0x7fec3390) = param_1;
              bVar3 = *(byte *)(iVar2 + -0x7fec3382) | 8;
            }
            else {
              if (param_4 != 3) {
                return;
              }
              iVar2 = (uVar4 * 0x200 - uVar6) * 8;
              *(undefined1 *)(iVar2 + -0x7fec3390) = param_1;
              bVar3 = *(byte *)(iVar2 + -0x7fec3382) | 0x80;
            }
            *(byte *)(iVar2 + -0x7fec3382) = bVar3;
          }
        }
        else {
          uVar6 = 0;
          iVar1 = uVar4 * 0xff8;
          FUN_800a7b64(param_1,param_2,(&DAT_8013cc54)[iVar1],param_4,param_3);
          iVar2 = iVar1;
          do {
            if (*(char *)(iVar2 + -0x7fec3e48) != (&DAT_8013cc54)[iVar1]) {
              FUN_800a7b64(param_1,param_2,*(char *)(iVar2 + -0x7fec3e48),0,0);
            }
            uVar6 = uVar6 + 1;
            iVar2 = uVar6 + iVar1;
          } while (uVar6 < 0x40);
        }
      }
      return;
    }
  }
  uVar4 = uVar4 | param_3 & 0x80000000;
  goto LAB_800a1434;
}
